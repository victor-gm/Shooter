#include "io.h"

void readFromBinary(int fd, void* readInfo, int offset, int numBytes)
{
    if(pread(fd,readInfo,numBytes,offset) == -1)
    {
        readInfo = 0;
    }
}

void printDataWithTitle(void* data, char* title, int type)
{
    if (type == 0)
    {
        char* data_local = (char*) data;

        char finalString [strlen(title)+ strlen(data_local) + 2];
        sprintf(finalString,"%s: %s\n",title, data_local);
        write(1,finalString,strlen(finalString));

    }
    else if (type == 1 || type == 2)
    {
        if(type == 1)
        {
            unsigned short* data_local = (unsigned short*) data;

            char finalString [strlen(title)+ sizeof(data_local) + 2];
            sprintf(finalString,"%s: %hn\n",title, data_local);
            write(1,finalString,strlen(finalString));

        }
        else if (type == 2)
        {
            unsigned int* data_local = (unsigned int*) data;

            char finalString [strlen(title)+ sizeof(data_local) + 2];
            sprintf(finalString,"%s: %ls\n",title, data_local);
            write(1,finalString,strlen(finalString));
        }
    }
   

    /*
    if(type == 0) // String
    {
        char finalString [strlen(title)+ strlen(data) + 2];
        sprintf(finalString,"%s: %s\n",title, (char*)data);
        write(1,finalString,strlen(finalString));
    }
    else
    {
        char finalString [strlen(title)+ sizeof(data) + 2];
        sprintf(finalString,"%s: %u\n",title, data);
        write(1,finalString,strlen(finalString));

    }*/
}


/*
void printStringWithTitle(char* data, char* title)
{
    char finalString [strlen(title)+ strlen(data) + 2];
    sprintf(finalString,"%s: %s\n",title, data);
    write(1,finalString,strlen(finalString));
}

void printIntWithTitle(unsigned int number, char* title)
{
    char finalString [strlen(title)+ 4 + 2];
    sprintf(finalString,"%s: %u\n",title, number);
    write(1,finalString,strlen(finalString));
}



unsigned int littleEndianToBigEndian(char* little, int size)
{
    unsigned int big = little[size - 1];
    for(int i = size - 1; i > 0; i--)
    {
        big = big << 8;
        big = big + little[i-1];
    }
    return big;
}

// Transforms the obtained string to a readable big endian integer
unsigned int obtainValue(int fd, int offset, int numBytes)
{
    char aux[numBytes];
    readFromBinary(fd, aux , offset, numBytes);
    return littleEndianToBigEndian(aux,numBytes);
}

void readFromBinary(int fd, char* readInfo,int offset, int numBytes, int isInteger)
{
    //int n = pread(fd,readInfo,numBytes,offset);
    if(pread(fd,readInfo,numBytes,offset) == -1)
    {
        readInfo = 0;
    }
    else if(isInteger && numBytes > 1) // We don't want / need / can't to swap  1 only byte
    {   
        littleEndianToBigEndian(readInfo,numBytes);
    }
    else if(numBytes == 1)
    {
        unsigned int test = *readInfo;
    }
}

void printFromBinary(char* data, char* title, int isInteger)
{
    char finalString [strlen(title)+ strlen(data) + 2];
    if(isInteger)
    {
        //unsigned int processed = littleEndianToBigEndian(data, strlen(data));
        //sprintf(finalString,"%u",processed);
        sprintf(finalString,"%s: %u\n",title, data);
    }
    else
    {
        sprintf(finalString,"%s: %s\n",title, data);
    }
    write(1,finalString,strlen(finalString));
}

//String to Int
unsigned int stoi(char* string, int size)
{
    unsigned int number = string[0];
    for(int i = 1 ; i < size  ; i++)
    {
        number = number << 8;
        number = number + string[i];
    }
    return number;
}

void littleEndianToBigEndian(char* string, int numBytes)
{
    char aux;
    for (int i = 0; i < numBytes - 1; i++)
    {
        aux = string[i];
        string[i] = string[numBytes - 1 - i];
        string[numBytes -1 - i] = aux;
    }
}

// Alternative version of the conversion that returns directly the unsigned int, now we have littleEndianToBigEndian + stoi
unsigned int littleEndianToBigEndian(char* little, int size)
{
    unsigned int big = little[size - 1];
    for(int i = size - 1; i > 0; i--)
    {
        big = big << 8;
        big = big + little[i-1];
    }
    return big;
}*/






