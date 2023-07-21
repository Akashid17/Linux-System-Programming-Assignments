//Write Program which accept file name from user and print all information about that file.

#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	struct stat sobj;
	int fd = 0;

	if(argc != 2)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}	

	fd = open(argv[1],O_RDONLY);
	fstat(fd,&sobj);

	printf("File: %s\n",argv[1]);
	printf("Size: %ld\n",sobj.st_size);
	printf("Blocks: %ld\n",sobj.st_blocks);
	printf("IO Blocks: %ld\n",sobj.st_blksize);	
	if(S_ISREG(sobj.st_mode))
	{
		printf("Regular File\n");
	}
	else if(S_ISDIR(sobj.st_mode))
	{
		printf("Directory File\n");
	}
	printf("Inode: %ld\n",sobj.st_ino);
	printf("Links: %ld\n",sobj.st_nlink);
	printf("File system number : %ld\n",sobj.st_dev);

	return 0;
}

/*
  File: Demo.txt
  Size: 33        	Blocks: 8          IO Block: 4096   regular file
Device: 807h/2055d	Inode: 27928425    Links: 1
Access: (0775/-rwxrwxr-x)  Uid: ( 1000/   akash)   Gid: ( 1000/   akash)
Access: 2023-07-14 18:48:36.742268652 +0530
Modify: 2023-07-14 18:48:31.210211554 +0530
Change: 2023-07-14 18:48:31.210211554 +0530
 Birth: 2023-07-14 14:21:23.695437939 +0530
------------------------------------------------------------
dev_t 		st_dev;		ID of device containing file  
ino_t 		st_ino; 	inode number 
mode_t 		st_mode; 	protection 
nlink_t 	st_nlink; 	number of hard links 
uid_t 		st_uid; 	user ID of owner  
gid_t 		st_gid; 	group ID of owner 
dev_t 		st_rdev; 	device ID (if special file) 
off_t 		st_size; 	total size, in bytes 
blksize_t 	st_blksize; blocksize for filesystem I/O  
blkcnt_t 	st_blocks;  number of 512B blocks allocated 
*/