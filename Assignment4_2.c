//write a program which accept directory name from user and create new directory of that name.

#include<stdio.h>

int main(int argc, char *argv[])
{
    int dp = 0;

    if(argc != 2)
    {
        printf("Insufficient argument\n");
        return -1;
    }

    dp = mkdir(argv[1],0777);
 
    if(dp == 0)
    {
        printf("directory created successfully\n");
    }
    else
    {
        printf("Unable to creat directory\n");
        return -1;
    }

    return 0;
}