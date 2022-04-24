#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int high,low,mid,n;
clock_t start, end;
double timetaken;
void combine(int a[], int low, int high, int mid);
void mergesort(int a[], int low, int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		combine(a,low,high,mid);
	}
}
void combine(int a[],int low, int high, int mid){
	int i,j,k;
	int temp[n];
	k=low;
	i=low;
	j=mid+1;
	while(i<=mid && j<=high){
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=high)
		temp[k++]=a[j++];
	for(i=low;i<=high;i++)
		a[i]=temp[i];
	printf("%d",temp[i]);
}
void main(){

	int i;
	printf("enter array size \n");
	scanf("%d",&n);
	int a[n];	
	for(int i=0;i<n;i++)
	{	 int r =rand();
		a[i]=r;
	}
	printf("before sorting : \n");
	for(i=0;i<n;i++)
		printf("%d \t",a[i]);
	start=clock();
	mergesort(a,0,n-1);
	end=clock();
	printf("\n after sorting \n");
	for(i=0;i<n;i++)
		printf("%d \t",a[i]);
	timetaken= (double)(end-start)/CLOCKS_PER_SEC;
	printf("%f",timetaken);
}
	
