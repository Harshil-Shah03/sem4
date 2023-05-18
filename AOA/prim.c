#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define n 5
#define INFINITY INT_MAX
int graph[n][n] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
int dist[10],i,j,k,par[10];
bool visited[10];
void initialize()
{
    for(i=0;i<n;i++)
    {
        dist[i]=INFINITY;
        par[i]=0;
        visited[i]=false;
    }
}
int min()
{
    int min= INFINITY,min_index=0;
    for(i=0;i<n;i++)
    {
        if(visited[i]==false && dist[i]<min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;

}

void prim()
{
    int u=0;
   
    initialize();
    dist[0]=0;
    visited[0]=true;
    par[0]=-1;
    for(j=0;j<n-1;j++)
    {
        u=min();
        visited[u]==true;
        for(k=0;k<n;k++)
        {
            if(visited[k]==false && graph[u][k]!=0 && graph[u][k]<dist[k])
            {
                dist[k]=graph[u][k];
                par[k]=u;
            }
        }
    }
    printf("\nparent-->destination\t\t\t\tdistance");
    for(i=0;i<n;i++)
    {
        printf("\n%d-->%d\t\t\t\t%d",par[i],i,dist[i]);
    }
}
int main()
{
    prim();
    return 0;
}