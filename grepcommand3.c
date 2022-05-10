#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 1024

void usage()
{
	printf("usage:\t. /a.out filename word \n");
}

int main(int argc, char *argv[])
{
	FILE *fp;
	char fline[max];
	char *newline;
	int count=0;
	int occurrences=0;
	char* tosearch=argv[2];
	
	if(argc!=3)
	{
		usage();
		exit(1);
	}
	
	if(!(fp=fopen(argv[1],"r")))
	{
		printf("grep: could not open file : %s \n",argv[1]);
		exit(1);
	}
	
	while(fgets(fline,max,fp)!=NULL)
	{
		count++;
		printf("%d  ",count);
		printf("%s  ",fline);
		int i=0, j=0, found=0,count=0, stringlen=0,searchlen=0;
		stringlen=strlen(fline);
		searchlen=strlen(argv[2]);
		for(i=0;i<stringlen-searchlen;i++)
		{
			found = 1;
        		for(j=0; j<searchlen; j++)
        		{
            			if(fline[i + j] != tosearch[j])
            			{
                			found = 0;
                			break;
            			}
        		}

        			if(found == 1)
        			{
            				count++;
        			}
		}

		printf("No of Occurences:%d\n", count);
		if(newline = strchr(fline, '\n'))
			*newline='\0';
		
	}
}


