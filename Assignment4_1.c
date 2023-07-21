#include<stdio.h>

int main(int argc, char *argv[])
{
    printf("name of application : %s\n",argv[0]);   
    if(argc == 1)
    {
        printf("Please enter your First name as command line argument\n");
        return -1;
    }
    else
    {
        printf("Welcome to Marvellous : %s \n",argv[1]);
        return 0;
    }
}