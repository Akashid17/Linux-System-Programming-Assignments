//write a program which accept two file names from user and copy the contents of existing file into newly created file.
#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
	int fdSource = 0;
	int fdDest = 0;
	char Buffer[BLOCKSIZE] = {'\0'};
	int Ret = 0;

	if(argc != 3)
	{
		printf("Insufficient argument\n");
		return -1;
	}

	fdSource = open(argv[1],O_RDONLY);

	if(fdSource == -1)
	{
		printf("Unable to open source file\n");
		return -1;
	}

	fdDest = creat(argv[2],0777);
	if(fdDest == -1)
	{
		printf("Unable to create destination file\n");
		close(fdSource);
		return -1;
	}

	while((Ret = read(fdSource,Buffer,sizeof(Buffer))) != 0)
	{
		write(fdDest,Buffer,Ret);
		memset(Buffer,0,sizeof(Buffer));
	}

	close(fdSource);
	close(fdDest);

	return 0;
}