//Write a program which accept file name from user and open that file in specfic mode.

#include<stdio.h>
#include<fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	int mode = 0;

	if(argc != 3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}

	if(strcmp(argv[2], "Read") == 0)
	{
		mode = O_RDONLY;
	}
	else if(strcmp(argv[2], "Write") == 0)
	{
		mode = O_WRONLY;
	}
	else
	{
		printf("Wrong mode entered\n");
		return -1;
	}

	fd = open(argv[1], mode);

	if(fd == 3)
	{
		printf("File opened succefully opend in %s mode\n",argv[2]);
	}
	else
	{
		printf("Unable to open File\n");
		return -1;
	}

	return 0;
}