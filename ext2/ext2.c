#include "ext2/ext2.h"
#include "io/io.h"

int testEXT(int fd)
{
    unsigned short magic;
    readFromBinary(fd,&magic,SUPERBLOCK+56,2);
    if(magic == 61267) // 61267 is the magic number in short!
    {   
        return 1;
    }
    return 0;
}

Ext2 EXT2_extractInfo(int fd)
{
    Ext2 ext2;
    readFromBinary(fd,&ext2.s_inode_size,SUPERBLOCK + 88,2);
    readFromBinary(fd,&ext2.s_inodes_count,SUPERBLOCK, 4);
    readFromBinary(fd,&ext2.s_first_ino, SUPERBLOCK + 84, 4);
    readFromBinary(fd,&ext2.s_inodes_per_group, SUPERBLOCK + 84, 4);
    readFromBinary(fd,&ext2.s_free_inodes_count, SUPERBLOCK + 16, 4);

    readFromBinary(fd,&ext2.s_log_block_size,SUPERBLOCK + 24,4);
    readFromBinary(fd,&ext2.s_r_blocks_count,SUPERBLOCK + 8,4);
    readFromBinary(fd,&ext2.s_free_blocks_count,SUPERBLOCK + 12,4);
    readFromBinary(fd,&ext2.s_blocks_count,SUPERBLOCK + 4,4);
    readFromBinary(fd,&ext2.s_first_data_block,SUPERBLOCK + 20,4);
    readFromBinary(fd,&ext2.s_blocks_per_group,SUPERBLOCK + 32,4);
    readFromBinary(fd,&ext2.s_frags_per_group,SUPERBLOCK + 36,4);

    readFromBinary(fd,&ext2.name,SUPERBLOCK + 120, 16);
    readFromBinary(fd,&ext2.lastcheck, SUPERBLOCK + 64,4);
    readFromBinary(fd,&ext2.s_mtime, SUPERBLOCK + 44,4);
    readFromBinary(fd,&ext2.s_wtime, SUPERBLOCK + 48,4);


    return ext2;
}

/*
EXT2_readInfo(Ext2 ext2)
{
    write(1,FILESYSTEM_EXT2, strlen(FILESYSTEM_EXT2));
    write(1,INFO_INODE, strlen(INFO_INODE));
    printDataWithTitle(ext2.s_inode_size,SIZE_INODE,1);
    printDataWithTitle(ext2.s_inodes_count,NUM_INODES,1);
    printDataWithTitle(ext2.s_first_ino,FIRST_INODE,1);
    printDataWithTitle(ext2.s_inodes_per_group,INODES_GROUP,1);
    printDataWithTitle(ext2.s_free_inodes_count,FREE_INODES,1);

    write(1, INFO_BLOCK, strlen(INFO_BLOCK));
    EXT2_printSizeBlock(ext2.s_log_block_size);
    printDataWithTitle(ext2.s_r_blocks_count,RESERVED_BLOCKS,1);
    printDataWithTitle(ext2.s_free_blocks_count,FREE_BLOCKS,1);
    printDataWithTitle(ext2.s_blocks_count,TOTAL_BLOCKS,1);
    printDataWithTitle(ext2.s_first_data_block,FIRST_BLOCK,1);
    printDataWithTitle(ext2.s_blocks_per_group,GROUP_BLOCK,1);
    printDataWithTitle(ext2.s_frags_per_group,FRAGS_GROUP,1);

    write(1, INFO_VOLUME, strlen(INFO_VOLUME));
    printDataWithTitle(ext2.name,VOLUME_NAME,0);
    printDataWithTitle(ctime(&ext2.lastcheck),LAST_CHECKED,0); //Check all /n's
    printDataWithTitle(ctime(&ext2.s_mtime),LAST_MOUNT,0);
    printDataWithTitle(ctime(&ext2.s_wtime),LAST_WRITE,0);
}

//Deals with log operations. Internal use only
void EXT2_printSizeBlock(int s_log_block_size)
{
    f(s_log_block_size > 0)
    {
        return printDataWithTitle(1024 << s_log_block_size, SIZE_BLOCK,1);
    }
    return printDataWithTitle(1024 >> -s_log_block_size, SIZE_BLOCK,1);
}*/








