// Write a program which accept directory name and delete all such files whose size is greater than 100 bytes.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    int bufferSize2 = 0;
    char *Buffer2 = NULL;

    if(argc != 3)
    {
		printf("Insufficient arguments\n");
		return -1;
    }

    fd = open(argv[1],O_RDWR);

    if(fd == -1)
    {
    	printf("Unable to open file\n");
    	return -1;
    }

    bufferSize2 = atoi(argv[2]);

    Buffer2 = (char*)malloc(bufferSize2*sizeof(char));

    read(fd,Buffer2,bufferSize2);

    close(fd);
    remove(argv[1]);
  
    creat(argv[1],0777);
    fd = open(argv[1],O_RDWR);
    write(fd,Buffer2,bufferSize2);
    close(fd);

	return 0;
}