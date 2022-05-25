#include<stdio.h>
#include<stdlib.h>
int w[10],p[10],v[10][10];
int n,m;
int max(int a,int b) //function to find max element
{
if(a>b)
{
return a;
}
else
{
return b;
}
}

void knapsack()
{
for(int i=0;i<=n;i++)
{
for(int j=0;j<=m;j++)
{

/*if no of objects or capacity of knapsack is 0, then profit is also 0*/
if(i==0&&j==0)
{
v[i][j]=0;
}

/*weight of object i is greater than remaining capacity of knapsack*/
else if(w[i]>j)
{
v[i][j]=v[i-1][j]; //i th object is rejected
}

/*weight of object i is lesser than remaining capacity of knapsack*/
else
{
v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]); //formula
}
}
}

printf("the optimum solution is %d\n",v[n][m]);
printf("tabular column is:\n"); //shows tracing of the knapsack problem
for(int i=0;i<n;i++)
{
for(int j=0;j<=m;j++)
{
printf("%d\t",v[i][j]);
}
printf("\n");
}
}

void element() //function to find optimum solution using formula
{
int x[n];
for(int i=0;i<n;i++)
{
x[i]=0;
}
int i=n;
int j=m;
while(i>0&&j>0)
{
if(v[i][j]!=v[i-1][j])
{
x[i]=1;
j=j-w[i];
}
i--;
}

for(int i=0;i<n;i++)
{
printf("%d\t",x[i]);
}
}

void main()
{
printf("Enter the capacity of the knapsack:\t");
scanf("%d",&m);
printf("Enter the number of elements:\t");
scanf("%d",&n);
printf("Enter the weights of the elements:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&w[i]);
}
printf("Enter the profits of each element:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&p[i]);
}
knapsack();
printf("\n");
element();
}