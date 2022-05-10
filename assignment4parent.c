#include<stdio.h>/*Used for printf and scanf*/
#include<unistd.h>/*Used for exec function types*/
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>/*Used for string copy fun*/

/*Function Declaration*/
void quicksort(int[] ,int,int);/*Quick Sort*/

/*Main Function*/
int main(void)
{
int pid = 0 ;/*Variable to store the pid*/
int value = 0;
int list[50] = {0};/*Accept elements to sort*/
char **buffer ;
int size = 0;/*Used for no. of elements to sort*/
int i =0;/*Used for 'for loop'*/
int x=0;
/*Accept no. of elements to sort*/
printf("\n\t Enter the number of elements: ");
scanf("%d",&size);

/*Accept Elements*/
printf("\n\t Enter the elements to be sorted : \n");
for(i=0;i<size;i++)
{
printf("\n\t Enter the %d element : \t",i+1);
scanf("%d",&list[i]);

}
buffer = malloc(size*sizeof(char*));
for(i=0;i<size;i++)
{
buffer[i]=malloc(size*sizeof(char));
}
pid=fork();/*now create new process*/
printf("\n\t PARENT PROCESS = %d \n ",getppid());
/*Sort Elements*/
quicksort(list,0,size-1);
printf("\n\tafter applying quicksort \n");
for(i=0;i<size;i++)
{
printf("\t%d\t",list[i]);
}
printf("\n");
for(i=0 ; i<size; i++)
{
sprintf(buffer[i],"%d",list[i]);/*buff to store size in bytes*/
}
buffer[i]='\0';
execve("child",buffer,NULL);/*executes an existing file*/
return 0;
}

/*Quick Sort*/
void quicksort(int list[],int low,int high)
{
int pivot,i,j,temp;
if(low < high)
{
pivot = low;//select pivot element
i= low;
j=high;
while(i < j)
{

while(list[i] <= list[pivot] && i <= high)//increment i

//when pivot is greater
{
i++;
}
while(list[j] > list[pivot] && i >= low)//decrement j

//when pivot is greater
{
j--;
}
if(i < j)//when i < j then perform swap
{
temp = list[i];
list[i] = list[j];
list[j] = temp;
}
}
temp=list[j];
list[j]= list[pivot];
list[pivot] = temp;
quicksort(list,low,j-1);
quicksort(list,j + 1,high);
}
}
