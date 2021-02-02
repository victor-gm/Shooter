
#include "utils/utils.h"

void freeString(char* s) 
{
    free(s);
    s = NULL;
}

