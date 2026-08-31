#include <stdio.h>
#define MAXE 500
int parent[100];
int find(int x){while(parent[x]!=x){parent[x]=parent[parent[x]];x=parent[x];}return x;}
void unite(int a,int b){a=find(a);b=find(b);if(a!=b)parent[b]=a;}
typedef struct{int u,v,w;}Edge;
int main(){Edge e[MAXE],t;int v,n,i,j,count=0,total=0;printf("Enter number of vertices: ");scanf("%d",&v);printf("Enter number of edges: ");scanf("%d",&n);printf("Enter edges (u v weight):\n");for(i=0;i<n;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);for(i=0;i<v;i++)parent[i]=i;for(i=0;i<n-1;i++)for(j=0;j<n-i-1;j++)if(e[j].w>e[j+1].w){t=e[j];e[j]=e[j+1];e[j+1]=t;}printf("Edges in Minimum Spanning Tree:\n");for(i=0;i<n&&count<v-1;i++){int a=find(e[i].u),b=find(e[i].v);if(a!=b){unite(a,b);printf("%d - %d : %d\n",e[i].u,e[i].v,e[i].w);total+=e[i].w;count++;}}printf("Minimum Cost = %d\n",total);return 0;}