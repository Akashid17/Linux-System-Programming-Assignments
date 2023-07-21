//write a program which accept directory name from user and copy first 10 bytes from all regular files into newly created file named as Demo.txt.

#include<stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <fcntl.h>

#define BUFFERSIZE 15

int main(int argc, char *argv[])
{
    int rfd = 0, wfd = 0;
    char Buffer[BUFFERSIZE] = {'\0'};
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj; 
    char fileName[50] = {'\0'};
    int ret = 0;

    if(argc != 2)
    {
        printf("Insufficient argument\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open direcoty\n");
    }

    wfd = creat("Demo.txt",0777);

    if(wfd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    wfd = open("Demo.txt",O_WRONLY);

    if(wfd == -1)
    {
        printf("Unable to open Demo.txt");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        if(entry->d_type != 4)
        {
            rfd = open(entry->d_name,O_RDONLY);

            if(rfd == -1)
            {
                printf("Unable to open files\n");
                return -1;
            }
            read(rfd,Buffer,BUFFERSIZE);
            write(wfd,Buffer,BUFFERSIZE);
            memset(Buffer,'\0',BUFFERSIZE);
        }
    }

    return 0;
}