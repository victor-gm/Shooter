#ifndef _FAT16_H
#define _FAT16_H

#include "lib.h"
/******************************************************************************************************
 											STRCUTURES													
*******************************************************************************************************/

// The intend of this structure is to save the data that we are going to need later to avoid double reading
typedef struct fat
{
    char FAT_TYPE[6]; //5 characters + \0
    char BS_OEMName [8];
    unsigned short BPB_BytsPerSec;
    char BPB_SecPerClus;
    unsigned short BPB_ResvdSecCnt;
    char BPB_NumFATs;
    unsigned short BPB_RootEntCnt;
    unsigned short BPB_FATSz16;
    unsigned int BPB_FATSz32;
    char BS_VolLab [9]; //8 characters + \0
}Fat;

typedef struct directory
{
    char file_name[8];
    char file_name_extension[3];
    char file_Atributes;
    char reserved[10];
    unsigned short time_created_or_last_updated;
    unsigned short date_created_or_last_updated;
    unsigned short file_starting_cluster_number;
    char file_size_in_bytes[4];
}Directory;

/***************************************************************************
 *                              STRINGS                                    *
 ***************************************************************************/
#define FILESYSTEM "Filesystem"
#define SYSTEM_NAME "System Name"
#define SECTOR_SIZE "Size Of The Sector"
#define SECTORS_PER_CLUSTER "Sectors Per Cluster"
#define RESERVED_SECTORS "Reserved Sectors"
#define NUM_FATs "Number of FATs"
#define MAX_ROOT_ENTRIES "MaxRootEntries"
#define SECTORS_FAT "Sectors Per FAT"
#define LABEL "Label"

#define OTHER_FS "FileSystem is not EXT2 or FAT16\n"

/***************************************************************************
 *                              VALUES                                     *
 ***************************************************************************/

#define FAT_12 "FAT12"
#define FAT_16 "FAT16"
#define FAT_32 "FAT32"
#define EXT_2   "EXT2"
#define UNDEFINED "UNDEFINED"

/***************************************************************************
 *                              FUNCTIONS                                  *
 ***************************************************************************/

void FAT16_readInfo(Fat fat);
char testFAT(int fd);
Fat detectFAT(int fd, int option);
Fat whichFAT(int fd);
void FAT16_find(int fd, Fat fat);




#endif 