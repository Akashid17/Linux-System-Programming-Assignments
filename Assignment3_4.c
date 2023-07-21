//write a program which accept two directory names from user and move all files from source directory to destination directory

#include<stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <fcntl.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char fileName[50] = {'\0'};

    if(argc != 2)
    {
        printf("Insufficient argument\n");
        return -1;
    }

    dp = opendir(argv[1]);
 
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(fileName,"%s/%s",argv[1],entry->d_name);
        stat(fileName,&sobj);

        if(sobj.st_size == 0)
        {
            remove(fileName);
        }
    }

    closedir(dp);
    return 0;
}