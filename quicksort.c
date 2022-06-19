#include<stdio.h>
#include<time.h>
#include<stdlib.h>
clock_t start, end;
double timetaken;
int first, last, n;

void quicksort(int a[], int first, int last){
    int i, j, pivot, temp;
    if(first<last){
        i = first;
        j = last;
        pivot = first;
        while(a[i] <= a[pivot] && i<=last)
            i++;
        while(a[j] >= a[pivot] && j>first)
            j--;
        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        quicksort(a, first, j-1);
        quicksort(a, j+1, last);
    }
}

void main(){
    int i;

    printf("Enter the size of the array: "); // Taking input of size of array
    scanf("%d", &n);
    srand(time(0));
    int a[n];
    for (i = 0; i < n; i++) // Using rand to generate a random no
    {
        int r = rand();
        a[i] = r;
    }
    start = clock();
    quicksort(a, 0, n - 1); // Calling the quicksort function
    end = clock();

    printf("After Sorting:"); // After Sorting
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    // End of for loop

    timetaken = (double)(end - start) / CLOCKS_PER_SEC; // Calculating the total time taken
    printf("Time taken is %1f", timetaken);
}