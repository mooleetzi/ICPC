#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 11111
struct Edge{
    int v,w,next;
}edge[MAXN<<1];
int NE,head[MAXN];
void addEdge(int u,int v,int w){
    edge[NE].v=v; edge[NE].w=w;
    edge[NE].next=head[u]; head[u]=NE++;
}
long long d[3][MAXN];
int idx[MAXN];
void dfs0(int u,int fa){
    long long mx0=0,mx1=0;
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(v==fa) continue;
        dfs0(v,u);
        if(mx0<=d[0][v]+edge[i].w) mx1=mx0,mx0=d[0][v]+edge[i].w,idx[u]=v;
        else if(mx1<d[0][v]+edge[i].w) mx1=d[0][v]+edge[i].w;
        else if(mx1<d[1][v]+edge[i].w) mx1=d[1][v]+edge[i].w;
        if (u==1)
            d[0][u]=max(d[0][u],d[0][v]);
    }
    d[0][u]=mx0; d[1][u]=mx1;
}
void dfs1(int u,int fa){
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(v==fa) continue;
        if(idx[u]==v) d[2][v]=max(d[1][u]+edge[i].w,d[2][u]+edge[i].w);
        else d[2][v]=max(d[0][u]+edge[i].w,d[2][u]+edge[i].w);
        if (u==1||fa==1)
            d[2][u]=max(d[2][u],d[2][v]);
        dfs1(v,u);
    }
}
int main(){
    int n,a,b;
    while(~scanf("%d",&n)){
        NE=0;
        memset(head,-1,sizeof(head));
        for(int i=2; i<=n; ++i){
            int c;
            scanf("%d%d%d",&a,&b,&c);
            addEdge(b,a,c);
        }
        memset(d,0,sizeof(d));
        dfs0(1,1);
        dfs1(1,1);
        for(int i=1; i<=n; ++i){
            printf("%lld\n",max(d[0][i],d[2][i]));
        }
    }
    return 0;
}
