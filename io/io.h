#ifndef _IO_H
#define _IO_H

#include "lib.h"
#include "utils/utils.h"

#define FILE_NOT_FOUND_ERR "Error, the specified file doesn't exist\n"

void readFromBinary(int fd, void* readInfo,int offset, int numBytes);
void printDataWithTitle(void* data, char* title, int type);

/*unsigned int obtainValue(int fd, int offset, int numBytes);
unsigned int littleEndianToBigEndian(char* little, int size);
void printStringWithTitle(char* data, char* title);
void printIntWithTitle(unsigned int number, char* title);
//unsigned int stoi(char* string, int numBytes);*/

#endif