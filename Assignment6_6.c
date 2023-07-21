// Write a program which accept directory name from user and create hole in file if size is less than 1KB & if it is greater than 1KB then truncate the remaining data.

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
    int bufferSize2 = 0;
    char *Buffer2 = NULL;

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
			    fd = open(fileName,O_RDWR);

			    if(fd == -1)
			    {
			    	printf("Unable to open file\n");
			    	return -1;
			    }

			    bufferSize2 = MAX;

			    Buffer2 = (char*)malloc(bufferSize2*sizeof(char));

			    read(fd,Buffer2,bufferSize2);

			    close(fd);
			    remove(fileName);
			  
			    creat(fileName,0777);
			    fd = open(fileName,O_RDWR);
			    write(fd,Buffer2,bufferSize2);
			    close(fd);
		}
		else if(sobj.st_size < MAX && S_ISREG(sobj.st_mode))
		{
			bufferSize2 = MAX-sobj.st_size;

			Buffer2 = (char*)malloc(bufferSize2*sizeof(char));
			
			fd = open(fileName,O_RDWR);

			lseek(fd,0,SEEK_END);
			write(fd,Buffer2,bufferSize2);
		}
	}

	closedir(dp);

	return 0;
}