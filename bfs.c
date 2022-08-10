#include<stdio.h>
int n, i, j, visited[100], a[100][100], front, rear, u, source, q[100];

void bfs(int , int a[100][100], int[100], int);
void main(){
    printf("enter number of vertices \n");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
        visited[i] = 0;
    printf("enter adjacency matrix \n");
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d", &a[i][j]);
    printf("enter source node \n");
    scanf("%d", &source);
    visited[source] = 1;
    bfs(source, a, visited, n);
}

void bfs(int source, int a[100][100], int visited[100], int n){
    rear = -1;
    front = 0;
    // visited[source] = 1;
    q[++rear] = source;
    while(front<=rear){
        u = q[front++];
        for(i=1; i<=n; i++){
            if(visited[i]==0 && a[u][i]==1){
                visited[i] = 1;
                q[++rear] = i;
            }
        }
    printf("%d \t", u);
    }
}