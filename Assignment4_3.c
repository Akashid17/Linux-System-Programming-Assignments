//write a program which accept directory name from user and check whether contents of that two files are equal or not

#include<stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0;
    char Buffer1[BUFFERSIZE] = {'\0'};
    char Buffer2[BUFFERSIZE] = {'\0'};
    struct stat obj1, obj2;
    int ret = 0;

    if(argc != 3)
    {
        printf("Insufficient argument\n");
        return -1;
    }

    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);

    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Contents of files are diffenrent\n");
        return -1;
    }

    while((ret = read(fd1,Buffer1,BUFFERSIZE)) != 0)
    {
        ret = read(fd2,Buffer2,BUFFERSIZE);

        if(memcmp(Buffer1,Buffer2,ret) != 0)
        {
            break;
        }
    }

    if(ret == 0)
    {
        printf("Both files are identical\n");
    }
    else
    {
        printf("Both files are different\n");
    }

    close(fd1);
    close(fd2);

    return 0;
}