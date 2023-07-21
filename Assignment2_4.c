//Write a Program which accept directory name from user and print all file names and its types from that directory

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

	printf("Files from Directory : File Types\n\n");

	while((entry = readdir(dp)) != NULL)
	{
		printf("%20s : ",entry->d_name);

		if(entry->d_type == 8)
		{
			printf("Regular file\n");
		}
		else if(entry->d_type == 4)
		{
			printf("Directory file\n");
		}
		else
		{
			printf("File type not found\n");
		}
	}

	closedir(dp);

	return 0;
}