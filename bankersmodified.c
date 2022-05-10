// Banker's Algorithm
#include <stdio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void show();

void show() {
	int i,j;
	printf("Process\t Allocation\t Max\t Available\t\t");
	for(i=0;i<n;i++) {
	printf("\nP%d\t ",i+1);
	for(j=0;j<r;j++) {
		printf("%d ",alloc[i][j]); 
	}
	printf("\t\t");
	for(j=0;j<r;j++) {
		printf("%d ",max[i][j]); }
		printf("\t");
		if(i==0) {
			for(j=0;j<r;j++)
			printf("%d ",avail[j]);
			}
		}
	}

int main()
{
	// P0, P1, P2, P3, P4 are the Process names here

	int i,j, k;
	printf("Enter the no of Processes\t");
	scanf("%d",&n);
	printf("Enter the no of resources instances\t");

	scanf("%d",&r);
	printf("Enter the Max Matrix\n");

	for(i=0;i<n;i++) {
		for(j=0;j<r;j++) {
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the Allocation Matrix\n");

	for(i=0;i<n;i++) {
		for(j=0;j<r;j++) {
			scanf("%d",&alloc[i][j]);
		}	
	}
	printf("Enter the available Resources\n");

	for(j=0;j<r;j++) {
		scanf("%d",&avail[j]);
	}

	show();

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][r];
	for (i = 0; i < n; i++) {
		for (j = 0; j < r; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < r; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < r; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(f[i]==0)
	{
		flag=0;
		printf("\nThe following system is not safe");
		break;
	}
	}
	
	if(flag==1)
	{
	printf("\n\nFollowing is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);
	}
	

	return (0);

	

}
