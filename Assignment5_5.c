// Write a program which accept file name which contains data of all file. we have to create all file again.

#include<stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
	struct dirent *entry = NULL;
	DIR *dp = NULL;
	char fileName[30] = {'\0'};
	int fd = 0, ret = 0, newfd = 0;
	struct FileInfo fobj;

	if(argc != 2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}

	fd = open(argv[1],O_RDONLY);

	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	while(ret = read(fd,&fobj,sizeof(fobj)) != 0)
	{
		newfd = creat(fobj.FileName,0777);
		if(newfd == -1)
		{
			printf("Unable to create file\n");
			return -1;
		}
	}

	close(fd);
	close(newfd);

	return 0;
}