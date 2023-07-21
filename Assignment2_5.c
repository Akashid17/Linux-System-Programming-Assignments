//Write a Program which accept directory name from user and print names of such file having largest size.

#include<stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	DIR *dp = NULL;
	struct dirent * entry = NULL;
	struct stat sobj;
	int fd = 0;
	int size = 0;
	char filename[50] = {'\0'};
	char name[50] = {'\0'};

	if(argc != 2)
	{
		printf("Invalid numbers of arguments\n");
		return -1;
	}

	dp = opendir(argv[1]);

	if(dp == NULL)
	{
		printf("Unable to open Directory\n");
		return -1;
	}

	while((entry = readdir(dp)) != NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&sobj);
		
		if(sobj.st_size > size)
		{
			memset(filename, '\0', sizeof(filename));
			size = sobj.st_size;
			strcpy(filename,entry->d_name);
		}
	}

	printf("Largest file is %s with size %d\n",filename,size);

	closedir(dp);

	return 0;
}