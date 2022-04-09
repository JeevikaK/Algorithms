#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j;
void main()
{
	int n;int temp;
	printf("enter array size \n");
	scanf("%d",&n);
	int a[n];
	clock_t start,end;
	double timetaken;
	srand(time(0));
//	printf("enter array \n");
	for(i=0;i<n;i++)
//		scanf("%d",&a[i]);
	{	int r = rand();
		a[i]=r;
	}
	printf("before sorting \n");
	for(i=0;i<n;i++)
	{	
		printf("%d \t",a[i]);
	}
	start=clock();
	for(i=0;i<n-1;i++)
	{	for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	end=clock();
	timetaken = (double)(end-start)/CLOCKS_PER_SEC;
	printf("sorted array: \n");
	for(i=0;i<n;i++)
		printf("%d \t",a[i]);
	printf("\n");
	printf("time taken = %1f", timetaken);
}


