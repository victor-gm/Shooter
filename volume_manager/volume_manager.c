#include "volume_manager/volume_manager.h"

void find(char* path, char* file_name)
{
    int fd = openVolume(path);
    Fat fat;
    switch(detectFileSystem(fd))
    {
        case 0: fat = detectFAT(fd,1);
                FAT16_find(fd,fat);
                break;
        case 1: write(1,SYSTEM_INFO,strlen(SYSTEM_INFO)); //EXT_2
                /*Ext2 ext2 = EXT2_extractInfo(fd);
                EXT2_readInfo(ext2);*/
                break;
        default: write(1,OTHER_FS,strlen(OTHER_FS)); //OTHER
                 break;      
    }   
}

void readInfo(char* path)
{   
    int fd = openVolume(path);
    switch(detectFileSystem(fd))
    {
        case 0: detectFAT(fd,0);
                break;
        case 1: write(1,SYSTEM_INFO,strlen(SYSTEM_INFO)); //EXT_2
                /*Ext2 ext2 = EXT2_extractInfo(fd);
                EXT2_readInfo(ext2);*/
                break;
        default: write(1,OTHER_FS,strlen(OTHER_FS)); //OTHER
                 break;      
    }   
}

int openVolume(char* path)
{
    int fd = open(path, O_RDONLY);
	if (fd < 0) 
	{
		write(1, VOLUME_NOT_FOUND_ERR, strlen(VOLUME_NOT_FOUND_ERR));
	    return -1;
	}
    return fd;
}

int detectFileSystem(int fd)
{   
    unsigned int BPB_NumFATs = testFAT(fd); // The only value that I'm forced to re-read
    if (BPB_NumFATs >= 1)
    {   
        return 0;
    }
    else if (testEXT(fd))
    {
        return 1;
    }
    else
    {
        return 2;
    }
    return -1; // UNDEFINED;
}








