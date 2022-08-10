#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int t[500], i, j, k;

void shifttable(char p[]){
    int m = strlen(p);
    for(i=0; i<500; i++)
        t[i] = m;
    for(j=0; j<m-1; j++)
        t[p[j]] = m-1-j;
}

int horspool(char p[], char src[]){
    int m = strlen(p);
    int n = strlen(src);
    printf("length of pattern = %d", m);
    printf("length of source = %d \n", n);
    i=m-1;
    while(i<n){
        k=0;
        while(k<m && p[m-1-k]==src[i-k]){
            k++;
        }
        if(k==m)
            return i-m+1;
        else
            i+=t[src[i]];
    }
}

void main(){
    char p[100]; char src[500];
    printf("enter the pattern \n");
    gets(p);
    printf("enter the source \n");
    gets(src);
    int position = horspool(p, src);
    if(position>=0)
        printf("pattern found at %d", position+1);
    else
        printf("pattern not found \n");
}