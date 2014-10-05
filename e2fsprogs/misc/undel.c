/**
 * @file e2fsprogs/misc/undel.h 
 * @author Copyright (C) 2009 Antonio Davoli, Vasile Claudiu Perta.
 */

#include <stdio.h>
#include <string.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_ERRNO_H
#include <errno.h>
#endif
#include <fcntl.h>
#include <time.h>
#if HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif

#include "../lib/ext2fs/ext2_fs.h"
#include "../lib/ext2fs/ext2fs.h"
#include "../lib/e2p/e2p.h"

#include "undel.h"

static int ex3u_default_fifo_size(__u64 blocks);

__u64 ext3u_max_size = 0;
__u32 ext3u_fifo_reserved = 0;
__u32 ext3u_skip_reserved = 0;
__u32 ext3u_index_reserved = 0;
__u32 ext3u_skip_extlen = 0;


struct mk_ext3u_struct {
	int			num_blocks;
	int			newblocks;
	blk_t		goal;
	blk_t		blk_to_zero;
	int			zero_count;
	char		*buf;
	errcode_t	err;
};


/**
 * @brief Given the number of blocks in the filesystem, find a reasonable
 * size (in blocks) for the cache of the deleted files. We use almost the same 
 * number of blocks the journal uses.
 */
static int ext3u_default_fifo_size(__u64 blocks)
{
	if (blocks < 2048)
		return -1;
	if (blocks < 32768)
		return (1024);
	if (blocks < 256*1024)
		return (4096);
	if (blocks < 512*1024)
		return (8192);
	if (blocks < 1024*1024)
		return (8192);
	return 8192;
}


/**
 * @brief Validate the options specified by the user.
 * 
 */
static int ext3u_validate_options(ext2_filsys fs)
{
	__u64 blocks = fs->super->s_blocks_count;

	/* Set the number of blocks used for the FIFO list */
	
	if (!ext3u_fifo_reserved) {
		ext3u_fifo_reserved = ext3u_default_fifo_size(blocks);
	}

	if (EXT3u_WRONG_FIFO_SIZE(ext3u_fifo_reserved)) {
		fprintf(stderr, "\n\n[ ext3u ] error: 'cache-blocks' size requested is %d blocks; it must be between %d and %d blocks\n",
				 ext3u_fifo_reserved, EXT3u_FIFO_SIZE_MIN, EXT3u_FIFO_SIZE_MAX);	
		return ENOMEM;
	}

	/* Set the maximum size of the deleted files. */

	if (!ext3u_max_size) {
		/* The option 'maxdel' not used, set the default size. */
		ext3u_max_size = ext3u_default_fs_size(fs->super->s_blocks_count);
	} else {
		/* The option 'maxdel' was used. Since it specify  */
		/* the size in MB, we must  convert it in blocks */
		switch (fs->blocksize) {
	
			case 1024:
				ext3u_max_size = (ext3u_max_size * 1024);
				break;
			case 2048:
				ext3u_max_size = (ext3u_max_size * 512);
				break;
			case 4096:	
				ext3u_max_size = (ext3u_max_size * 128);
				break;
		}	
	}

	if ((ext3u_max_size < EXT3u_DEL_SIZE_MIN(blocks)) || (ext3u_max_size > EXT3u_DEL_SIZE_MAX(blocks))) {
		fprintf(stderr, "\n\n[ ext3u ] error: 'max-data' size requested is %lld blocks; it must be between %lld and %lld blocks\n",
				 ext3u_max_size, EXT3u_DEL_SIZE_MIN(blocks), EXT3u_DEL_SIZE_MAX(blocks));
		return ENOMEM;
	}

	ext3u_skip_reserved = EXT3u_SKIP_RESERVED;
	ext3u_skip_extlen = EXT3u_SKIP_EXTLEN;

	return 0;
}

static int mk_ext3u_proc(ext2_filsys	fs,
			   			blk_t		*blocknr,
			  		 	e2_blkcnt_t	blockcnt,
			   			blk_t		ref_block EXT2FS_ATTR((unused)),
			   			int			ref_offset EXT2FS_ATTR((unused)),
			   			void		*priv_data)
{
	struct mk_ext3u_struct *es = (struct mk_ext3u_struct *) priv_data;
	blk_t	new_blk;
	errcode_t	retval;


	if (*blocknr) {
		es->goal = *blocknr;
		return 0;
	}
	retval = ext2fs_new_block(fs, es->goal, 0, &new_blk);
	if (retval) {
		es->err = retval;
		return BLOCK_ABORT;
	}
	if (blockcnt >= 0)
		es->num_blocks--;

	es->newblocks++;
	retval = 0;

	
	if (blockcnt <= 0)
		retval = io_channel_write_blk(fs->io, new_blk, 1, es->buf);
	else {
		if (es->zero_count) {
			if ((es->blk_to_zero + es->zero_count == new_blk) &&
			    (es->zero_count < 1024))
				es->zero_count++;
			else {
				retval = ext2fs_zero_blocks(fs, es->blk_to_zero, es->zero_count, 0, 0);
				es->zero_count = 0;
			}
		}
		if (es->zero_count == 0) {
			es->blk_to_zero = new_blk;
			es->zero_count = 1;
		}
	}
	
	if (blockcnt == 0)
		memset(es->buf, 0, fs->blocksize);

	if (retval) {
		es->err = retval;
		return BLOCK_ABORT;
	}
	*blocknr = es->goal = new_blk;
	ext2fs_block_alloc_stats(fs, new_blk, +1);

	if (es->num_blocks == 0)
		return (BLOCK_CHANGED | BLOCK_ABORT);
	else
		return BLOCK_CHANGED;

}

/**
 * @brief The first block of the EXT2_UNDEL_DIR_INO inode is
 * the ext3u superblock, which contains information to manage 
 * all the data structures.
 */

static errcode_t ext3u_create_superblock(ext2_filsys fs,  __u32 flags, char  **ret_usb)
{
	errcode_t		retval;
	struct ext3u_super_block *usb;
		
	if ((retval = ext2fs_get_mem(fs->blocksize, &usb)))
		return retval;

	memset (usb, 0, fs->blocksize);

	usb->s_flags = flags;
	usb->s_block_size = fs->blocksize;
	usb->s_inode_size = fs->super->s_inode_size;

	usb->s_fifo.f_blocks = ext3u_fifo_reserved;
	usb->s_fifo.f_start_block = 1;
	usb->s_fifo.f_last_block = 1;
	usb->s_fifo.f_last_offset = EXT3u_BLOCK_HEADER_SIZE;
	usb->s_fifo.f_last_block_remaining = fs->blocksize - EXT3u_BLOCK_HEADER_SIZE;
	usb->s_fifo.f_free = (ext3u_fifo_reserved) * (fs->blocksize - EXT3u_BLOCK_HEADER_SIZE); 
	usb->s_fifo_free = (ext3u_fifo_reserved) * (fs->blocksize - EXT3u_BLOCK_HEADER_SIZE); 

	usb->s_skip.s_size = ext3u_skip_reserved;
	usb->s_skip.s_filext_size = ext3u_skip_extlen;

	usb->s_del.d_max_size = ext3u_max_size * fs->blocksize;
	usb->s_del.d_max_filesize = (ext3u_fifo_reserved * (fs->blocksize - EXT3u_BLOCK_HEADER_SIZE));
	
	*ret_usb = (char *) usb;
	return 0;
}


/**
 * @brief Write the EXT3u_UNDEL_DIR_INO inode.  
 */

static errcode_t ext3u_write_inode(ext2_filsys fs, ext2_ino_t undel_ino, int flags)
{

	char				*buf;
	errcode_t			retval;
	struct ext2_inode	inode;
	struct mk_ext3u_struct	es;
	__u32 num_blocks = ext3u_fifo_reserved + ext3u_skip_reserved + ext3u_index_reserved + 1;

	if ((retval = ext3u_create_superblock(fs, flags, &buf)))
		return retval;

	if ((retval = ext2fs_read_bitmaps(fs)))
		return retval;

	if ((retval = ext2fs_read_inode(fs, undel_ino, &inode)))
		return retval;

	if (inode.i_blocks > 0)
		return EEXIST;

	es.goal = 0;
	es.num_blocks = num_blocks;
	es.newblocks = 0;
	es.buf = buf;
	es.err = 0;
	es.zero_count = 0;

	retval = ext2fs_block_iterate2(fs, undel_ino, BLOCK_FLAG_APPEND, 0, mk_ext3u_proc, &es);
	if (es.err) {
		retval = es.err;
		goto errout;
	}
	if (es.zero_count) {
		retval = ext2fs_zero_blocks(fs, es.blk_to_zero, es.zero_count, 0, 0);
		if (retval)
			goto errout;
	}

	 if ((retval = ext2fs_read_inode(fs, undel_ino, &inode)))
		goto errout;

 	inode.i_size += fs->blocksize * num_blocks;
	ext2fs_iblk_add_blocks(fs, &inode, es.newblocks);
	inode.i_mtime = inode.i_ctime = fs->now ? fs->now : time(0);
	inode.i_links_count = 1;
	inode.i_mode = LINUX_S_IFREG | 0600;

	if ((retval = ext2fs_write_inode(fs, undel_ino, &inode)))
		goto errout;
	retval = 0;


errout:
	ext2fs_free_mem(&buf);
	return retval;
}


/**
 * @brief Add the EXT3u_UNDEL_DIR_INO inode to the ext3 filesystem.
 */
static errcode_t ext3u_add_inode(ext2_filsys fs, int flags)
{
	errcode_t  retval;
	ext2_ino_t	ino;

	ext2_ino_t undel_ino = EXT3u_UNDEL_DIR_INO;
	
	if ((retval = ext3u_write_inode(fs, undel_ino, flags)))
		return retval;

	ext2fs_mark_super_dirty(fs);

	return 0;
}

/**
 * @brief Add undelete capabilities to the ext3 filesystem
 */

void ext3u_init(ext2_filsys fs)
{
	errcode_t err;	
	__u32 flags;

	if ( (err = ext3u_validate_options(fs)) || (err = ext3u_add_inode(fs, flags)) ){
		printf("[ ext3u ] Cannot add the undelete support.\n\n\n");
	} else {

		fs->super->s_feature_compat |= EXT3u_FEATURE_COMPAT_UNDELETE;

		printf("\n\n");
		printf("[ ext3u ] Cache size=%d blocks\n", ext3u_fifo_reserved);
		printf("[ ext3u ] Saving files up to %lld bytes\n", ext3u_max_size * fs->blocksize);
		printf("[ ext3u ] Undelete support successfuly added ! \n");
		printf("\n\n");
	}

	ext2fs_mark_super_dirty(fs);
}


/**
 * @brief Parse the ext3u options
 */
void parse_ext3u_opts(const char *opts)
{
	char *buf, *token, *next, *p, *arg;
	int	len, ext3u_usage = 0;

	len = strlen(opts);
	buf = malloc(len + 1);

	if (!buf) {
		fputs("Couldn't allocate memory to parse undel "
			"options!\n", stderr);
		exit(1);
	}
	strcpy(buf, opts);

	for (token = buf; token && *token; token = next) {
		p = strchr(token, ',');
		next = 0;

		if (p) {
			*p = 0;
			next = p+1;
		}
		arg = strchr(token, '=');

		if (arg) {
			*arg = 0;
			arg++;
		}
	
		if (strcmp(token, "max-data") == 0) {
			if (!arg) {
				ext3u_usage++;
				continue;
			}
			char * z = (arg + strlen(arg) - 1);
			switch(*z){
				case 'M':
					*z='\0';
					break;
				default:
					printf("mkfs.ext3: unknown unit type for 'max-data'; use M (megabytes).\n");
					ext3u_usage++;
					continue;
			}
			ext3u_max_size = strtoul(arg, &p, 0);
			if (*p)
				ext3u_usage++;
		} else if (strcmp(token, "cache-blocks") == 0) {
			if (!arg) {
				ext3u_usage++;
				continue;
			}
			ext3u_fifo_reserved = strtoul(arg, &p, 0);
			if (*p)
				ext3u_usage++;
		} else
				ext3u_usage++;
	}
	if (ext3u_usage) {
		fprintf(stderr, "mkfs.ext3: bad ext3u options specified.\n\n"
						"The ext3u options are separated by commas, and may take\n"
						"an argument which is set off by an equals ('=') sign.\n"
						"Valid options are:\n"
						"\tmax-data=N (maximum reachable size in Mb for the data blocks)\n"
						"\tcache-blocks=N (size in blocks of the deleted files cache )\n");
		free(buf);

		exit(1);
	}
	free(buf);
}

