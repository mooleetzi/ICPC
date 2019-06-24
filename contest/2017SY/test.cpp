#include<stdio.h>
#include<string.h>
const int maxn=110;
int vis[maxn];
typedef struct edge{
	int to;
	struct edge *next;
	edge(){
		next=NULL;
	}
}edge;
typedef struct node{
	int data;
	edge *first;
	node(){
		first=NULL;
		data=0;
	}
}node;
typedef struct List{
	node vet[maxn];
	int vetNum,edgeNum;
}List;
void createList(List&g){
	cout<<"please input the vetNum && edgeNum of this graph:\n";
	cin>>g.vetNum>>g.edgeNum;
	cout<<"please input each edge in a line:\n";
	for (int i=0;i<g.edgeNum;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		edge *now=new edge();
		now->to=y;
		now->next=g.vet[x].first;
		g.vet[x].first=now;
		g.vet[x].data++;
		g.vet[y].data++;
		now=new edge();
		now->to=x;
		now->next=g.vet[y].first;
		g.vet[y].first=now;
	}
	printf("created.\n");
}
void dfs(List&g,int cur){
	vis[cur]=1;
	printf("%d ",cur);
	for (edge *now=g.vet[cur].first;now!=NULL;now=now->next){
		int to=now->to;
		if (!vis[to])
			dfs(g,to);
	}
}
void bfs(List&g,int s){
	int q[maxn*2];
	memset(vis,0,sizeof vis);
	memset(q,0,sizeof q);
	int h=0,t=1;
	q[0]=s;
	vis[s]=1;
	while(h<t){
		int now=q[h++];
		printf("%d ",now);
		for (edge *cur=g.vet[now].first;cur!=NULL;cur=cur->next){
			int to=cur->to;
			if (!vis[to]){
				q[t++]=to;
				vis[to]=1;
			}
		}
	}
}
int main()
{
    printf("------------adj list--------------\n");
	List g;
	createList(g);
	printf("the permutation of dfs:\n");
	dfs(g,1);
	printf("\nthe permutation of bfs:\n");
	bfs(g,1);
    return 0;
}
