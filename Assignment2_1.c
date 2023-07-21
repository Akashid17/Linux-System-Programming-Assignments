//Write Program which accept file name from user and read whole file.

#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
	int fd = 0;
	int Ret = 0;
	char buffer[BLOCKSIZE] = {'\0'};

	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}

	fd = open(argv[1],O_RDONLY);

	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}	

	while((Ret = read(fd,buffer,BLOCKSIZE))!= 0)
	{
		write(1,buffer,Ret);
		memset(buffer,0,BLOCKSIZE);
	}

	printf("\n");
	close(fd);

	return 0;
}