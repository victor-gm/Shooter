#ifndef _EXT2_H
#define _EXT2_H

#include "lib.h"

/***************************************************************************
 *                              VALUES                                     *
 ***************************************************************************/

#define SUPERBLOCK 1024

/******************************************************************************************************
 											STRCUTURES													
*******************************************************************************************************/

// The intend of this structure is to save the data that we are going to need later to avoid double reading
typedef struct ext2
{
    unsigned short s_inode_size;
    unsigned int   s_inodes_count;
    unsigned int   s_first_ino;
    unsigned int   s_inodes_per_group;
    unsigned int   s_free_inodes_count;
    unsigned int   s_log_block_size; //Check
    unsigned int   s_r_blocks_count;
    unsigned int   s_free_blocks_count;
    unsigned int   s_blocks_count;
    unsigned int   s_first_data_block;
    unsigned int   s_blocks_per_group;
    unsigned int   s_frags_per_group;
    char           name[17]; // 16 + 1

    time_t *   lastcheck;
    time_t *   s_mtime; // Last mount
    time_t *  s_wtime; // Last write
    
}Ext2;

/***************************************************************************
 *                              STRINGS                                    *
 ***************************************************************************/

#define FILESYSTEM_EXT2 "\nFilesystem: EXT 2\n"

#define INFO_INODE "\nINFO INODE\n"
#define SIZE_INODE "Size of Inode"
#define NUM_INODES "Number Of Inodes"
#define FIRST_INODE "First Inode"
#define INODES_GROUP "Inodes Group"
#define FREE_INODES "Free Inodes"

#define INFO_BLOCK "\nINFO BLOCK\n"
#define SIZE_BLOCK "Size Of Block"
#define RESERVED_BLOCKS "Reserved Blocks"
#define FREE_BLOCKS "Free Blocks"
#define TOTAL_BLOCKS "Total Blocks"
#define FIRST_BLOCK "First Block"
#define GROUP_BLOCK "Group Block"
#define FRAGS_GROUP "Frags Group"

#define INFO_VOLUME "\nINFO VOLUME\n"
#define VOLUME_NAME "Volume Name"
#define LAST_CHECKED "Last Checked"
#define LAST_MOUNT "Last Mount"
#define LAST_WRITE "Last Write"

/***************************************************************************
 *                              FUNCTIONS                                  *
 ***************************************************************************/

int testEXT(int fd);
Ext2 EXT2_extractInfo(int fd);
//void EXT2_readInfo(Ext2);
//void EXT2_printSizeBlock(int s_log_block_size);

#endif