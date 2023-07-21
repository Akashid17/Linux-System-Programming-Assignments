//Write a program which accept file name from user write string in that file.

#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	char *string = NULL;
	int stringSize = 0;

	if(argc != 3)
	{
		printf("Invalid numbers of arguments\n");
		return -1;
	}

	stringSize = strlen(argv[2]);

	string = (char*)malloc(stringSize*sizeof(char));

	strcpy(string,argv[2]);

	fd = open(argv[1],O_WRONLY);

	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	write(fd,string,stringSize);
		
	close(fd);

	return 0;
}