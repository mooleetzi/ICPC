#include<stdio.h>
#include<string.h>
#define maxn 110
typedef struct graph{
	int vetNum,edgeNum;
	int vet[maxn],vis[maxn];
	int edge[maxn][maxn];
}graph;
graph g;
void createGraph(){
    memset(g.vet,0,sizeof g.vet);
    memset(g.edge,0,sizeof g.edge);
	printf("������ͼ�Ľ�����ͱ���:\n");
	scanf("%d%d",&g.vetNum,&g.edgeNum);
	printf("����������ÿ����:\n");
	for (int i=0;i<g.edgeNum;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g.edge[x][y]=g.edge[y][x]=1;
		g.vet[x]++;
		g.vet[y]++;
	}
	printf("����ɹ�.\n");
}
void dfs(int now){
	g.vis[now]=1;
	printf("%d ",now);
	for (int i=1;i<maxn;i++)
		if (!g.vis[i]&&g.edge[now][i]){
			dfs(i);
		}
}
void bfs(int s){
	int q[maxn*2];
	int h=0,t=1;
	q[0]=s;
	g.vis[s]=1;
	while(h<t){
		int now=q[h++];
		printf("%d ",now);
		for (int i=1;i<maxn;i++)
			if (!g.vis[i]&&g.edge[now][i]){
				q[t++]=i;
				g.vis[i]=1;
			}
	}
}
int main()
{
	printf("------------�ڽӾ���--------------\n");
	createGraph();
	printf("dfs ����:\n");
	dfs(1);
	printf("\n");
	memset(g.vis,0,sizeof g.vis);
	printf("bfs ����:\n");
	bfs(1);
    return 0;
}
