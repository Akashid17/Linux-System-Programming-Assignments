//Write Program which accept file name and number from user and read that number of bytes from file.

#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd = 0;
	int bufferSize = 0;
	char *buffer = NULL;

	bufferSize = atoi(argv[2]);

	buffer = (char *)malloc(bufferSize*sizeof(char));

	if(buffer == NULL)
	{
		printf("Unable to allocate memory for read buffer\n");
		return -1;
	}

	fd = open(argv[1],O_RDONLY);

	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}	

	read(fd,buffer,bufferSize);
	
	write(1,buffer,bufferSize);
	
	printf("\n");
	close(fd);

	return 0;
}