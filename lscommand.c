#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
int main(int argc, char **argv)
{
	DIR *dp;
	struct dirent *link;
	char dirname[10];
	printf("Enter the directory name:\n");
	scanf("%s",dirname);
	dp=opendir(dirname);
	if(dp==NULL)
		{
			perror("Cannot find directory!!");
			exit(-1);
		}
	printf("\n Contents of the directory %s are:\n",dirname);
	while(link = readdir(dp))
		printf("%s\n", link->d_name);
	closedir(dp);
}
