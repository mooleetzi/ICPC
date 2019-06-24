#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include <queue>
using namespace std;
#define Maxn 1010
#define Maxe 10020
#define INF 1000000000
struct node{
	int to,val;
	node() {}
	node(int a,int b)
	{
		to = a; val = b;
	}
};
vector<node> adj[Maxe],_adj[Maxe];
int n,m,k;
int vis[Maxn];
int dis[Maxn];
void AddEdge(int x,int y,int val)
{
	adj[x].push_back(node(y,val));
	_adj[y].push_back(node(x,val));
}
void Dijkstra(int s,int t)
{
	priority_queue<int , vector<int> , greater<int> > q;
	while(!q.empty()) q.pop();

	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	vis[t] = 1; dis[t] = 0; q.push(t);
	int u,len;
	while(!q.empty())
	{
		u = q.top();  q.pop();
		len = _adj[u].size();
		for(int i=0;i<len;++i)
		{
			node v = _adj[u][i];
			if(dis[v.to] > dis[u] + v.val)
			{
				dis[v.to] = dis[u] + v.val;
				if(!vis[v.to])
				{
					q.push(v.to);
					vis[v.to] = 1;
				}
			}
		}
		vis[u] = 0;
	}
}

struct Anode{
	int h,g,id;
	Anode(int a,int b,int c) {h=a; g=b; id=c;}
	int operator < (Anode a) const
	{
		return h+g > a.h+a.g;
	}
};

priority_queue<Anode> Q;

int Astar(int s,int t)
{
	while(!Q.empty()) Q.pop();
	Q.push(Anode(0,dis[s],s));

	int len,num;
	num = 0;
	while(!Q.empty())
	{
		Anode u = Q.top(); Q.pop();
		if(u.id==t) ++num;
		if(num>=k) return u.h;

		len = adj[u.id].size();
		for(int i=0;i<len;++i)
		{
			node v = adj[u.id][i];
			Q.push(Anode(u.h+v.val,dis[v.to],v.to));
		}
	}

	return -1;
}

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
	    int time,s,t;
	    scanf("%d%d%d%d",&s,&t,&k,&time);
		for(int i=0;i<Maxn;++i) adj[i].clear(),_adj[i].clear();
		int x,y,v;
		for(int i=1;i<=m;++i)
		{
			scanf("%d%d%d",&x,&y,&v);
			AddEdge(x,y,v);
			//AddEdge(y,x,v);
		}
		if(s==t) ++k;
		Dijkstra(s,t);
		int ans=Astar(s,t);
		printf("%d\n",ans);
		if (ans<=time&&ans!=-1)
            printf("yareyaredawa\n");
        else
            printf("Whitesnake!\n");
	}
	return 0;
}
