// Write a program which creat hole of size 1KB at the end of file.

#include<stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>

#define HOLE 1024

int main(int argc, char *argv[])
{
	char HoleData[HOLE];
	int fd = 0;

	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}

	fd = open(argv[1],O_WRONLY);

	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	lseek(fd,0,SEEK_END);
	write(fd,HoleData,sizeof(HoleData));

	close(fd);

	return 0;
}