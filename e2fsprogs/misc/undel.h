/**
 * @file e2fsprogs/misc/undel.h
 * @author Copyright (C) 2009 Antonio Davoli, Vasile Claudiu Perta.
 */


#ifndef _UNDEL_H
#define _UNDEL_H

#include <limits.h>
#include "../lib/ext2fs/ext2fs.h"

#define EXT3u_FEATURE_INDEX 			0x0001

#define EXT3u_FEATURE_COMPAT_UNDELETE 	0x4000

#define EXT3u_BLOCK_HEADER_SIZE			4

#ifndef MIN
#define MIN(a,b) ( (a) <= (b) ? (a) : (b) )
#endif

#define EXT3u_SKIP_RESERVED		0

#define EXT3u_SKIP_EXTLEN		0

#define EXT3u_FIFO_SIZE_MIN		512

#define EXT3u_FIFO_SIZE_MAX		32768

#define EXT3u_FIFO_NULL(r) (((r)->r_offset == 0) ? 1 : 0)

#define EXT3u_FIFO_EMPTY(usb) (EXT3u_FIFO_NULL((&((usb)->s_fifo.f_first))))

#define EXT3u_WRONG_FIFO_SIZE(x) ( ((x) < EXT3u_FIFO_SIZE_MIN) || ((x) > EXT3u_FIFO_SIZE_MAX) )

#define EXT3u_UNDEL_DIR_INO		EXT2_UNDEL_DIR_INO

#define EXT3u_DEL_SIZE_MIN(blocks)	(blocks / 10)

#define EXT3u_DEL_SIZE_MAX(blocks)	(blocks / 4)	

#define ext3u_default_fs_size(blocks) (blocks / 10)



extern __u64  ext3u_max_size;
extern __u32  ext3u_fifo_reserved;


/* Pointer to an entry in the FIFO list */
struct ext3u_record {
	__u32 r_block; 		/* logical block number */
	__u64 r_real_block;	/* fisical block number */
	__u16 r_offset; 	/* offset in block */
	__u16 r_size; 		/* size of this entry */
};


/* FIFO information */
struct ext3u_fifo_info {
	__u32 				f_blocks;				/* blocks reserved for the fifo queue */
	__u32				f_start_block; 			/* first logical block of the fifo queue */
	__u32				f_last_block; 			/* last logical block used  */
	__u32				f_last_offset; 			/* offset in the last available block  */
	__u32				f_last_block_remaining;	/* space left on the last used block */
	__u32				f_free;					/* free space on the fifo (in bytes) */
	struct ext3u_record f_first;
	struct ext3u_record f_last;
};

/* Information about the deleted files */
struct ext3u_del_info {
	__u64 d_max_size;		/* max allowed size for ext3u filesystem (nr. of blocks) */
	__u64 d_max_filesize;	/* max allowed size for a file in order to be saved */
	__u64 d_current_size;	/* current size */
	__u32 d_file_count; 	/* current number of all saved directories */
	__u32 d_dir_count; 		/* current number of saved files */
};

/* Static entry used to insert or read an entry from the fifo queue */
struct ext3u_del_entry {
	__u16					d_size;				/* size in bytes of this entry */
	struct ext3u_record 	d_next;				/* pointer to next entry in the fifo list*/	
	struct ext3u_record		d_previous;			/* pointer to the previous entry in the fifo list */
	__u16					d_type;				/* flag specifying the type of this entry: file, directory, link*/
	__u32					d_hash;				/* hash of the file */
	__u16					d_path_length;		/* path length */
	__u16					d_mode;				/* */
	__u16		 			d_uid;				/* */
	struct ext2_inode 		d_inode;			/* inode of the deleted file */
	__u32					d_padding;			/* there are 4 bytes */
	unsigned char 			d_path[PATH_MAX+1];	/* buffer for the path */
};


/* We use this structure to restore the FIFO pointers after un 'undelete' */
struct ext3u_del_entry_header {
	__u16					d_size;				/* size in bytes of this entry */
	struct ext3u_record 	d_next;				/* pointer to next entry in the fifo list*/	
	struct ext3u_record		d_previous;			/* pointer to the previous entry in the fifo list */
	__u16					d_type;				/* type of this entry */
	__u32					d_hash;				/* hash of the path */
	__u16					d_path_length;
	__u16 					d_mode;
	__u16					d_uid;
};

#define EXT3u_DEL_HEADER_SIZE (sizeof(struct ext3u_del_entry_header))
#define EXT3u_DEL_ENTRY_SIZE (EXT3u_DEL_HEADER_SIZE + sizeof(struct ext3_inode))


/* Information about files/directories to skip */
struct ext3u_skip_info {
	__u32 s_dir_count; 			/* number af the directories  */
	__u32 s_filext_size;		/* bytes reserved for the extensions */
	__u32 s_filext_count; 		/* number of the extensions to filter */
	__u32 s_current_size;		/* current size */
	__u32 s_size; 				/* number of reserved blocks */

};


/* Skip entry */
struct ext3u_skip_entry {
	__u32 s_path_length;	/* directory path length */
	__u32 s_file_max_size;	/* skip files bigger than this */
	__u32 s_filext_length; 	/* extensions length */
};


/* Information about ext3u filesystem. */
struct ext3u_super_block {
	__u32	s_flags;
	__u32	s_block_size;		/* block size in bytes */
	__u32	s_inode_size;		/* inode size */
	__u32	s_fifo_free;		/* free space in the fifo list, including holes */
	__u64	s_block_count;		/* total number of used blocks */
	__u64	s_low_watermark; 	
	__u64	s_high_watermark;

	struct ext3u_del_info	s_del;
	struct ext3u_fifo_info 	s_fifo;
	struct ext3u_skip_info	s_skip;

};


void ext3u_init(ext2_filsys fs);
void parse_ext3u_opts(const char *opts);
void ext3u_print_super_block(struct ext3u_super_block * usb);
void ext3u_print_entry(struct ext3u_del_entry * de);

#endif
