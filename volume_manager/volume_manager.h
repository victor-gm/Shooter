#ifndef _VOLUME_MANAGER_H
#define _VOLUME_MANAGER_H

#include "lib.h"
#include "fat16/fat16.h"
#include "ext2/ext2.h"

/***************************************************************************
 *                              STRINGS                                    *
 ***************************************************************************/

#define VOLUME_NOT_FOUND_ERR "Error, the specified volume doesn't exist\n"

/***************************************************************************
 *                              FUNCTIONS                                  *
 ***************************************************************************/

void readInfo(char* path);
void find(char* path, char* file_name);
int detectFileSystem(int fd);
int openVolume(char* path);


#endif
