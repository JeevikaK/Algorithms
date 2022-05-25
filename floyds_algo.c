#include<stdio.h>
#include<stdlib.h>
int m;//declaration of size of array

int min(int a,int b)//maximum function
{
	if(a>b)
	return b;
	
	else
	return a;
}

void floyds(int a[100][100])//floyd's algorithm
{
	for(int k=0;k<m;k++)
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<m;j++)
			{
			a[i][j]=min(a[i][j],(a[i][k]+a[k][j]));//application of floyd's algorithm
			}
		}
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d\t",a[i][j]);//printing of the shortest path matrix
		}
		printf("\n");
	}
}

void main()
{
	printf("enter the order of the matrix:\t");
	scanf("%d",&m);//input of order of the adjacency matrix
	int a[100][100];//declaration of the adjacency matrix
	printf("enter the elements of the adjacency matrix:\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);//input of adjacency matrix
		}
	}
	
	floyds(a);//calling the floyds function
}
