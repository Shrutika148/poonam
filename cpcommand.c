#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	fp=fopen(argv[1],"r"); //open the file to be copied
	if(fp==NULL)
	{
		printf("Unable to open the file!!");
	}
	else
	{
		FILE *fq;
		fq=fopen(argv[2],"a");//open another file in append mode
		while(!feof(fp)) //till the contents of source file is not finished
		{
			ch=fgetc(fp);
			if(ch!=-1)
			{
				fputc(ch,fq);
			}
		}
		fclose(fq);
		fclose(fp);
	}
return 0;
}
