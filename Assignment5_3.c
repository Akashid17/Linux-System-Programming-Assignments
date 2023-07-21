// Write a program which accept directory name from user and write information of all regular file in and then read the contents from that file.

#include<stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	struct dirent *entry = NULL;
	DIR *dp = NULL;
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
		if(entry->d_type != 4)
		{
			sprintf(fileName,"%s/%s",argv[1],entry->d_name);
			printf("File Name : %s\n",fileName);
		}
	}

	return 0;
}