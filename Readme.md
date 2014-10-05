Support for recovery of deleted files in the ext3 filesystem. Namely, this functionality was implemented by: 

* creating a new module for the kernel 2.6.27 (see ext3u)
* modifying existing commands (mkfs.ext3 and fsck, see e2fsprogs)
* creating new user commands (ext3u-utils)
