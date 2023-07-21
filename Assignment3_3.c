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
    char oldname[50];
    char newname[50];

    if(argc != 3)
    {
    	printf("Invalid numbers of arguments\n");
    	return-1;
    }

    dp = opendir(argv[1]);
 
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(oldname,"%s/%s",argv[1],entry->d_name);
        sprintf(newname,"%s/%s",argv[2],entry->d_name);

        rename(oldname,newname);
    }

    closedir(dp);
    return 0;
}