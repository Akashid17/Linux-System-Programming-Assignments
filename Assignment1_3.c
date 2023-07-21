//Write a program which accept file name and mode from user check whether our file can access that file in accepted mode or not.

#include<stdio.h>
#include<fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int Ret = 0;
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

	Ret = access(argv[1], mode);

	if(Ret == 0)
	{
		printf("File can be access in %s mode\n",argv[2]);
	}
	else
	{
		printf("File is not accessible\n");
		return -1;
	}

	return 0;
}