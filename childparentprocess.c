#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 

int main(void)  
{ 
	int a[6] = {1,2,3,4,5,6}; 
	printf("\n Given array is:\t"); 
	for(int i=0;i<6;++i) 
	{ 
		printf("%d\t",a[i]); 
	}
	printf("\n"); 
 	pid_t pid = fork(); 

	if(pid == 0)  
	{ 
		printf("\nChild process created.\n"); 
 		printf("\nChild => PPID:%d PID: %d\n", getppid(), getpid()); 
 		for(int i = 0; i<6 ;i++) 
 		{ 
 			a[i] = a[i] * a[i]; 
 		} 
		printf("\nSquare of numbers in array:\t"); 
		for(int i=0;i<6;++i) 
		{ 
			printf("%d\t",a[i]); 
		} 
		printf("\n"); 
 		exit(EXIT_SUCCESS); 
	}

	else if(pid > 0)  
	{ 
		printf("\n We are in Parent Process.\n"); 
		printf("\nParent => PPID: %d PID: %d\n", getppid(), getpid());  
		for(int i = 0; i<6 ;i++) 
 		{ 
 			a[i] = a[i] * a[i] * a[i]; 
 		} 
		printf("\nCube of numbers in array:\t");
		for(int i=0;i<6;++i) 
		{ 
			printf("%d\t",a[i]); 
		} 
		printf("\n");

		printf("Waiting for child process to finish.\n\n"); 
 		wait (NULL); 
 		printf("\n Child process finished.\n"); 
 	} 
 	else  
	{ 
 		printf("\nUnable to create child process.\n"); 
	} 
} 


 


