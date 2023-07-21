// Write a program which accept directory name and file name from user and create file in that directory.

#include<stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	DIR *dp = NULL;
    struct dirent *entry = NULL;
    int fd = 0;
    char fileName[30] = {'\0'};

    if(argc != 3)
    {
		printf("Insufficient arguments\n");
		return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
    	printf("Unable to open directory\n");
    	return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
    	if(strcmp(entry->d_name,argv[2]) == 0)
    	{
    		printf("File is alredy present\n");
    		return-1;
    	}
    }

	sprintf(fileName,"%s/%s",argv[1],argv[2]);

	fd = creat(fileName,0777);

	if(fd == -1)
	{
		printf("Unable to create file\n");
		return -1;
	}

	printf("File created successfully\n");

	close(fd);
	closedir(dp);

	return 0;
}