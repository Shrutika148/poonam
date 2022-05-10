#include<stdio.h>
#include<dirent.h>
#include<string.h>
int main(int argc, char **argv)
{
DIR *dp;
struct dirent *link;
char arr[100][100] = {'\0'};
dp = opendir(argv[1]);
int cnt = 0;
printf("Contents of directory are : \n");
while((link = readdir(dp)) != 0)
{
printf("%s\t", link->d_name);
strcpy(arr[cnt], link->d_name);
cnt++;
}
printf("\nContents of directory in reverse order are : \n");
while(cnt>=0)
{
printf("%s\t",arr[cnt-1]);
cnt--;
}
closedir(dp);
}
