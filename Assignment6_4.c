// Write a program which accept directory name and delete all such files whose size is greater than 100 bytes.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define MAX 100

int main(int argc, char *argv[])
{
	DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    int fd = 0;
    char fileName[30] = {'\0'};

    if(argc != 2)
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
    	sprintf(fileName,"%s/%s",argv[1],entry->d_name);
    	stat(fileName,&sobj);

		if(sobj.st_size > MAX && S_ISREG(sobj.st_mode))
		{
			fd = remove(fileName);
			if(fd == 0)
			{
				printf("File removed = File name : %s File size : %d\n",entry->d_name,sobj.st_size);
			}
			else
			{
				printf("Unable to delete file\n");
				return -1;
			}
		}
	}

	closedir(dp);

	return 0;
}