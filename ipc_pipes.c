// C program to illustrate
// pipe system call in C
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#define MSGSIZE 100
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";

int main()
{
	char inbuf[MSGSIZE];
	int p[2], i, n;
	char msg[100] = "";
	if (pipe(p) < 0)
	{
		exit(1);
	}
	/* continued */
	/* write pipe */
	
	for (i = 1; i > 0; i++) {

		printf("\n1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 0 to Exit");
		printf("\nEnter your choice:");
		scanf("%d", &n);

		// Switch Cases
		switch (n) 
		{
			case 1:
				printf("Enter message to be added to pipe: ");
				scanf("%s", msg);
				write(p[1], msg, MSGSIZE);
				break;

			case 2:
				/* read pipe */
				read(p[0], inbuf, MSGSIZE);
				printf("%s\n", inbuf);
				break;

			// Exit Condition
			case 0:
				exit(0);
				break;
		}
	}
	return 0;
}

