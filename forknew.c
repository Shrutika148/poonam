#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
int main(void)  
{ 
	fork();
	printf ("\nHello \n Process id= %d\n", getpid());
	printf ("\n Parent Process id= %d\n", getppid());
	return(0);
}

