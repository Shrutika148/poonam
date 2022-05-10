#include<stdio.h>
#include<string.h>
int main()
{
	char pattern[20];
	char temp[100];
	char filename[20];
	FILE *fp=NULL;
	int count=0;
	int i=0;
	int j=0;
	int flag=0;
	printf("Enter the pattern: ");
	scanf("%s",pattern);
	printf("Enter filename: ");
	scanf("%s", filename);
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("File not opened\n");
	}
	else
	{
		while(!feof(fp))
		{
			fgets(temp,100,fp);
			i=0;
			flag=0;
			count=0;
			
			//This while loop checks whether the pattern has matched and
			//sets flag to 1 if yes
			while(temp[i]!='\0')
			{
				j=0;
				while(temp[i]==pattern[j])
		 		{
					i++;
					j++;
					if(pattern[j]=='\0')
					{
						flag=1;
						count++;
						break;
					}
				}
				i++;
			}

			int flag2=0;
			int k=0;

			//if flag is 1, i.e pattern has been matched
			if(flag)
			{
				i=0;
				while(temp[i]!='\0')
				{
					j=0;
					k=j;
					while(temp[i]==pattern[j])
					{
						i++;
						j++;
						flag2=1;
						if(pattern[j]=='\0')
						{
							printf("\033[0;31m");
							printf("%s",pattern);
							printf("\033[0m");
							flag2=0;
							break;
						}
					}
					if(flag2==1)
					{
						while(k<j)
						{
							printf("%c",temp[k]);
							k++;
						}
					}
					if(temp[i]!='\0')
					{
						printf("%c",temp[i]);
					}
					i++;
				}
				//printf("%d\n",count);
			}
		}
	}
}
