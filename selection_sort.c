#include<stdio.h>
#include<time.h>
void main()
{
	int i,j,n;
	int temp,min;
	printf("enter array size \n");
	scanf("%d",&n);
	int a[n];
	clock_t start,end;
	double totaltime;
	srand(time(0));
//	printf("enter array \n");
	for(i=0;i<n;i++)
//		scanf("%d",&a[i]);
	{
		int r = rand();
		a[i]=r;
	}
	printf("before sorting: \n");
	for(i=0;i<n;i++)
		printf("%d \t",a[i]);
	start=clock();
	for(i=0;i<n-1;i++)
	{	min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	end=clock();
	totaltime= (double)(end-start)/CLOCKS_PER_SEC;
	printf("\n sorted array: \n");
	for(i=0;i<n;i++)
		printf("%e \t",a[i]);
	printf("time taken =%f ",totaltime);

}
