#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,q,cnt,ans=0;
bool vis[maxn];
int head[maxn],deep[maxn],dis[maxn],fa[maxn][11];
struct data{int to,next,v;}e[2*maxn];
void ins(int u,int v,int w)
{e[++cnt].to=v;e[cnt].next=head[u];e[cnt].v=w;head[u]=cnt;}
void insert(int u,int v,int w){
    ins(u,v,w);
    ins(v,u,w);
}
void dfs(int x)
{
    vis[x]=1;
    for(int i=1;i<=9;i++)
    {
        if(deep[x]<(1<<i)) break;
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    ans+=dis[x];
    for(int i=head[x];i;i=e[i].next)
    {
        if(vis[e[i].to]) continue;
        deep[e[i].to]=deep[x]+1;
        dis[e[i].to]=dis[x]+e[i].v;
        ans+=dis[e[i].to];
        fa[e[i].to][0]=x;
        dfs(e[i].to);
    }
}
int lca(int x,int y)
{
    if(deep[x]<deep[y]) swap(x,y);
    int d=deep[x]-deep[y];
    for(int i=0;i<=9;i++)
        if((1<<i)&d) x=fa[x][i];
    for(int i=9;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            {x=fa[x][i];y=fa[y][i];}
    if(x==y) return x;
    else return fa[x][0];
}
//ll getAns(ll x){
//
//}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        insert(u,v,w);
    }
    dfs(1);
    printf("%d",ans-2*dis[1]);
//    for (int i=1;i<n;i++)
//        for (int j=i+1;j<=n;j++)
//            ans+=dis[i]+dis[j]-2*dis[lca(i,j)];
//    printf("%lld",getAns(ans));
    return 0;
}
