#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <ctime>
#include <cmath>
#include <cctype>
using namespace std;
#define maxn 1005
#define LL long long
int cas=1,T;
const int INF = 1<<25;
int mapp[1005][1005];
int d[maxn];
int n,m;

int dijkstra()
{
	int vis[maxn];
	int v;
	int mins;
	for (int i = 1;i<=n;i++)
	{
		d[i]=mapp[1][i];
		vis[i]=0;
	}
	d[1]=0;
	for (int i = 1;i<=n;i++)
	{
		mins = -1;
		for (int j = 1;j<=n;j++)
		{
			if (!vis[j] && d[j] > mins)
			{
				mins = d[j];
				v=j;
			}
		}
		vis[v]=1;
		for (int j = 1;j<=n;j++)
		{
			if (!vis[j] && d[j] < min(d[v],mapp[v][j]))
				d[j]=min(d[v],mapp[v][j]);
		}
	}
	return d[n];
}
int main()
{
	//freopen("in","r",stdin);
	scanf("%d",&T);
	while (T--)
	{
		memset(mapp,0,sizeof(mapp));
		printf("Scenario #%d:\n",cas++);

		scanf("%d%d",&n,&m);
		for (int i = 1;i<=m;i++)
		{
           int a,b,c;
		   scanf("%d%d%d",&a,&b,&c);
		   mapp[a][b]=c;
		   mapp[b][a]=c;
		}
		printf("%d\n\n",dijkstra());
	}
	return 0;
}
