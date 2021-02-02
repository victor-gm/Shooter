#include "fat16/fat16.h"
#include "io/io.h"

char testFAT(int fd)
{
    unsigned int BPB_NumFATs;
    readFromBinary(fd, &BPB_NumFATs, 16, 1);
    return BPB_NumFATs;
}

Fat detectFAT(int fd, int option)
{
    Fat fat = whichFAT(fd); // We reserve space for the structure once we've made sure it's gonna be a FAT volume

    if(strcmp(fat.FAT_TYPE,FAT_12) == 0)
    {
        write(1,OTHER_FS,strlen(OTHER_FS));
    }
    else if(strcmp(fat.FAT_TYPE,FAT_16) == 0)
    {
        write(1,SYSTEM_INFO,strlen(SYSTEM_INFO)); // FAT_16
        if(option == 0) FAT16_readInfo(fat);
    }
    else 
    {
        write(1,OTHER_FS,strlen(OTHER_FS)); //FAT_32
    }   

    return fat;
}

Fat whichFAT(int fd)
{  
    Fat fat;
    unsigned short TotSec,FATSz,BPB_TotSec32,BPB_TotSec16; 

    readFromBinary(fd, &fat.BS_OEMName,3,8);
    readFromBinary(fd, &fat.BPB_BytsPerSec,11,2);
    readFromBinary(fd, &fat.BPB_SecPerClus,13,1);
    readFromBinary(fd, &fat.BPB_ResvdSecCnt,14,2);
    readFromBinary(fd, &fat.BPB_NumFATs,16,1);
    readFromBinary(fd, &fat.BPB_RootEntCnt,17,2);
    readFromBinary(fd, &(BPB_TotSec16),19,2);
    readFromBinary(fd, &fat.BPB_FATSz16 ,22,2);
    readFromBinary(fd, &BPB_TotSec32,32,4);
    readFromBinary(fd, &fat.BPB_FATSz32,36,4);
    readFromBinary(fd, &fat.BS_VolLab,43,11);

    if(fat.BPB_FATSz16 != 0)
    {
        FATSz = fat.BPB_FATSz16;
    }
    else
    {
        FATSz = fat.BPB_FATSz32;
    }
    //printf("BPB_TotSec16: %hu\n",BPB_TotSec16);

    if(BPB_TotSec16 != 0)
    {
        TotSec = BPB_TotSec16 ;
    }
    else
    {
        TotSec = BPB_TotSec32;
    }
    unsigned int RootDirSectors = (unsigned int)floor (((fat.BPB_RootEntCnt * 32) + (fat.BPB_BytsPerSec - 1)) / fat.BPB_BytsPerSec);
    unsigned int DataSec = (unsigned int) TotSec - (fat.BPB_ResvdSecCnt + (fat.BPB_NumFATs * FATSz) + RootDirSectors);  
    unsigned int CountofClusters = (unsigned int)floor (DataSec / fat.BPB_SecPerClus);

    /*printf("------------------------------\n");
    printf("RootDirSectors: %d\n", RootDirSectors);
    printf("fat.BPB_RootEntCnt: %d\n", fat.BPB_RootEntCnt);

    printf("------------------------------\n");

    printf("------------------------------\n");
    printf("TotSec: %d\n", TotSec);
    printf("fat.BPB_ResvdSecCnt: %hu\n", fat.BPB_ResvdSecCnt);
    printf("fat.BPB_NumFATs: %hu\n", fat.BPB_NumFATs);
    printf("FATSz: %hu\n", FATSz);
    printf("------------------------------\n");


    printf("DataSec: %d\n", DataSec);
    printf("Count Of Clusters: %d\n", CountofClusters);*/
    if(CountofClusters < 4085) 
    {
        /* Volume is FAT12 */
        strcpy(fat.FAT_TYPE,FAT_12);
    } else if(CountofClusters < 65525) 
    {
        /* Volume is FAT16 */
        strcpy(fat.FAT_TYPE,FAT_16);
    } else 
    {
        /* Volume is FAT32 */
        strcpy(fat.FAT_TYPE,FAT_32);
    }
    return fat;
}

void FAT16_readInfo(Fat fat)
{
    printDataWithTitle(fat.FAT_TYPE,FILESYSTEM,0);
    printDataWithTitle(fat.BS_OEMName,SYSTEM_NAME,0); 
    printDataWithTitle(&(fat.BPB_BytsPerSec),SECTOR_SIZE,1);
    //printDataWithTitle(fat.BPB_SecPerClus,SECTORS_PER_CLUSTER,1);
    /*printDataWithTitle(fat.BPB_ResvdSecCnt,RESERVED_SECTORS,1);
    printDataWithTitle(fat.BPB_NumFATs,NUM_FATs,1);
    printDataWithTitle(fat.BPB_RootEntCnt,MAX_ROOT_ENTRIES,1);
    printDataWithTitle(fat.BPB_FATSz16,SECTORS_FAT,1);
    printDataWithTitle(fat.BS_VolLab,LABEL,0);*/
}

void FAT16_find(int fd, Fat fat)
{
    // Determine Position of Root Directory
    //int root_offset = (fat.BPB_NumFATs + 1) * fat.BPB_FATSz16;
    int reserved_sectors_size = (fat.BPB_ResvdSecCnt + 1) * fat.BPB_BytsPerSec; //Boot Sector + Reserved
    int fat_region_size = fat.BPB_NumFATs * fat.BPB_BytsPerSec;
    int root_offset = reserved_sectors_size + fat_region_size;
}





