//write a program which accept directory name and file name from user and check whether that file is present in that directory or not.

#include<stdio.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char directoryName[50] ={'\0'};
	char fileName[20] = {'\0'};
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	
	if(argc != 3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}

	dp =  opendir(argv[1]);

	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}

	while((entry = readdir(dp))!= NULL)
	{
		if(strcmp(entry->d_name,argv[2]) == 0)
		{
			break;
		}
	}

	if(entry != NULL)
	{
		printf("File is available in directory\n");
	}
	else
	{
		printf("File is not available in directory\n");
	}

	close(dp);

	return 0;
}