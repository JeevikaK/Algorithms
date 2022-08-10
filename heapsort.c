#include<stdio.h>
#include<time.h>

void heapify(int h[], int n){
    int i, j, k, n1, v, heap;
    n1=n;
    for(i=n1/2;i>=1;i--){
        k=i;
        v=h[k];
        heap=0;
        while(!heap && 2*k<=n){
            j=2*k;
            if(j<n)
                if(h[j]<h[j+1])
                    j=j+1;
            if(v>=h[j])
                heap=1;
            else{
                h[k]=h[j];
                k=j;
            }
            h[k]=v;
        }
    }
}

void main(){
    int n, r, t, size, i;
    clock_t start, end;
    double timetaken;
    printf("enter number of elements \n");
    scanf("%d", &n);
    int h[n];
    srand(time(0));
    for(i=1; i<=n; i++){
        r = rand();
        h[i] = r;
    }
    printf("before sorting = \n");
    for(i=1; i<=n; i++)
        printf("%d \t", h[i]);
    printf("\n");
    heapify(h, n);
    printf("after heapify= \n");
    for(i=1; i<=n; i++)
        printf("%d \t", h[i]);
    printf("\n");
    start = clock();
    for(i=n; i>=1; i--){
        t = h[1];
        h[1] = h[i];
        h[i] = t;
        size = i-1;
        heapify(h, size);
    }
    end = clock();
    printf("after sorting = \n");
    for(i=1; i<=n; i++)
        printf("%d \t", h[i]);
    timetaken = (double)(start-end)/CLOCKS_PER_SEC;
    printf("time taken = %f \n", timetaken);
}