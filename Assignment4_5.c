//write a program which accept file name and position from user and read 20 bytes from that position.

#include<stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <fcntl.h>

#define BUFFERSIZE 20

int main(int argc, char *argv[])
{
    int rfd = 0;
    char Buffer[BUFFERSIZE] = {'\0'};
    int ret = 0;

    if(argc != 3)
    {
        printf("Insufficient argument\n");
        return -1;
    }

    rfd = open(argv[1],O_RDONLY);

    if(rfd == -1)
    {
        printf("Unable to open file");
        return -1;
    }

    lseek(rfd,atoi(argv[2]),SEEK_SET);
    read(rfd,Buffer,BUFFERSIZE);
    write(1,Buffer,BUFFERSIZE);
    printf("\n");

    close(rfd);

    return 0;
}