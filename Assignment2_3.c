//Write a Program which accept directory name from user and print all file names from that directory

#include<stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR *dp = NULL;
	struct dirent * entry = NULL;

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

	printf("Files from Directory :\n");

	while((entry = readdir(dp)) != NULL)
	{
		printf("%s\n",entry->d_name);
	}

	closedir(dp);

	return 0;
}