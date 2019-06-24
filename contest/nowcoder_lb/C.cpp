#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 1001000;
struct Edge{
    int to,val,next;
};
Edge edge[maxn * 2];
bool vis[maxn];
int head[maxn];
int edgenum;
int dist[maxn];
int ans,Tnode;
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' | c > '9')c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        putchar(x / y + 48);
        x %= y;
    }
}
void init()
{
    memset(head,-1,sizeof(head));
    edgenum = 0;
}
void addEdge(int u,int v,int w)
{
    edge[edgenum].to = v;
    edge[edgenum].val = w;
    edge[edgenum].next = head[u];
    head[u] = edgenum++;
}
void BFS(int s)
{
    memset(vis,false,sizeof(vis));
    memset(dist,0,sizeof(dist));
    queue<int > q;
    q.push(s);
    ans = 0;
    dist[s] = 1;
    vis[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u] ; i != -1 ; i = edge[i].next)
        {
            int v = edge[i].to;
            if(!vis[v])
            {
                if(dist[v] < dist[u] + edge[i].val)
                    dist[v] = dist[u] + edge[i].val;
                vis[v] = true;
                q.push(v);
                if(ans < dist[v])
                {
                    ans = dist[v];
                    Tnode = v;
                }
            }
        }
    }
}
int main()
{
    int n,m,a,b,c;
    n=read();
    init();
    for(int i = 0 ; i < n-1 ; i++)
    {
        int x,y,z;
        x=read(),y=read();
        addEdge(x,y,1);
        addEdge(y,x,1);
    }
    ans = 0;
    BFS(1);//任一起点
    BFS(Tnode);//回来再走一遍
    write(ans);
   return 0;
}
