
#include "lib.h"
#include "utils/utils.h"
#include "volume_manager/volume_manager.h"

#define NO_ARGS                         "No arguments were introduced. Exiting...\n"

#define ARGS_ERROR_TOP 			        "Error with the number of arguments. For the option "
#define ARGS_ERROR_BOTTOM 		        "argument are expected\n"


#define ARGS_ERROR_INFO                  "info 1 "
#define ARGS_ERROR_FIND                  "find 2 "
#define ARGS_ERROR_DELETE                "delete 2 "

#define NO_VALID_OPTION                  "No valid option introduced. Valid options are: /info, /find or /delete\n"


#define ERROR_VOLUME_NOT_FOUND_TOP       "Volume "
#define ERROR_VOLUME_NOT_FOUND_BOTTOM    "not found "

int report_error(char* option)
{
    write(1, ARGS_ERROR_TOP, strlen(ARGS_ERROR_TOP));
    write(1, option, strlen(option));
    write(1, ARGS_ERROR_BOTTOM, strlen(ARGS_ERROR_BOTTOM));
    return EXIT_FAILURE;
}

int manage_arguments(int argc,char* argv[])
{
   if(argc <= 1)
	{
		write(1, NO_ARGS, strlen(NO_ARGS));
		return EXIT_FAILURE;
	}
    else if(strcasecmp(argv[1],"/info") == 0 )
    {
        if(argc == 3)
	    {
            readInfo(argv[2]);
        }
        else
        {
            report_error(ARGS_ERROR_INFO);
        }    
    }
    else if (strcasecmp(argv[1],"/find") == 0)
    {
       if(argc == 4)
	    {
            find (argv[2],argv[3]);
        }
        else
        {
            report_error(ARGS_ERROR_FIND);
        } 
    }
    else if (strcasecmp(argv[1],"/delete") == 0)
    {
       if(argc == 4)
	    {
            //int fd = openVolume(argv[2]);
        }
        else
        {
            report_error(ARGS_ERROR_DELETE);
        } 
    }
    else
    {
         write(1, NO_VALID_OPTION, strlen(NO_VALID_OPTION));
         return EXIT_FAILURE;
    }
    return 0;
}



int main (int argc,char* argv[])
{
	return manage_arguments(argc,argv);
}
