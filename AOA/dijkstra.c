#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<stdlib.h>
#define n 9
#define INFINITY INT_MAX
int graph[n][n] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
int dist[10],i,j,k,par[10],start_node=0;
bool visited[10];
void initialize()
{
    for(i=0;i<n;i++)
    {
        dist[i]=INFINITY;
        par[i]= start_node;
        visited[i]=false;
    }

}
int min()
{
    int min = INFINITY,min_ind = 0;
    for(i=0;i<n;i++)
    {
        if(visited[i]==false && dist[i]<min )
        {
            min = dist[i];
            min_ind=i;
        }
    }
    return min_ind; 
}
void dijkstra()
{
    int u;
    initialize();
    dist[0] = 0;
    par[0] = 0;
    visited[0]=true;
    for(j=0;j<n-1;j++)
    {
        u=min();
        visited[u]=true;
        for(k=0;k<n;k++)
        {
            if(visited[k]==false && graph[u][k]!=0 && dist[u]+graph[u][k]<dist[k])
            {
                dist[k]=dist[u]+graph[u][k];
                par[k]=u;
            }
        }

        
    }
    printf("\nnode\t\t\t\t\t\t\tdistance\t\t\t\t\t\t\tparent");
 for(i=0;i<n;i++)
 {
    printf("\n%d\t\t\t\t\t\t\t%d\t\t\t\t\t\t\t%d",i,dist[i],par[i]);

 }

}

int main()
{
    dijkstra();
    return 0;
}