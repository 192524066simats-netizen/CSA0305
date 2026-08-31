#include <stdio.h>
#define MAX 50
int a[MAX][MAX],vis[MAX],v;
void dfs(int u){int i;vis[u]=1;printf("%d ",u);for(i=0;i<v;i++)if(a[u][i]&&!vis[i])dfs(i);}
int main(){int i,j,s;printf("Enter number of vertices: ");scanf("%d",&v);printf("Enter adjacency matrix:\n");for(i=0;i<v;i++)for(j=0;j<v;j++)scanf("%d",&a[i][j]);printf("Enter starting vertex: ");scanf("%d",&s);printf("DFS Traversal:\n");dfs(s);printf("\n");return 0;}