#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[])
{
	char filename[20];
	char pattern[20];
	char temp[200];
	int count = 0;
	FILE *fp;
	printf("Enter the file name: ");
	scanf("%s",filename);
	printf("Enter the word to be searched: ");
	scanf("%s",pattern);

	fp = fopen(filename,"r");
	printf("Word found on line : ");
	while(!feof(fp))
	{
		count++;
		fgets(temp,1000,fp);
		if(strstr(temp,pattern))
		{
			printf("%d",count);
			printf("\n%s",temp);
			break;
		}

	}
	fclose(fp);

}
