#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
const int maxn=110;
int n,m;
int a[maxn][maxn];
int price[maxn],l[maxn],dis[maxn];
int vis[maxn];
int dijkstra(){
    for (int i=1;i<=m;i++)
        dis[i]=price[i];
    for (int i=1;i<m;i++){
        int u=-1,mins=0x3f3f3f3f;
        for (int j=1;j<=m;j++)
            if (!vis[j]&&dis[j]<mins)
                mins=dis[u=j];
        vis[u]=1;
        for (int j=1;j<=m;j++){
            if (!vis[j]&&a[u][j]+dis[u]<dis[j]){
                    dis[j]=a[u][j]+dis[u];
            }
        }
    }
    return dis[1];
}
int main(){
    scanf("%d%d",&n,&m);
    memset(a,0x3f,sizeof a);
    for (int i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        price[i]=x;
        l[i]=y;
        for (int j=0;j<z;j++){
            int to,w;
            scanf("%d%d",&to,&w);
            a[to][i]=w;
        }
    }
    int ans=0x3f3f3f3f;
    for (int i=1;i<=m;i++){
        int maxl=l[i];
        memset(vis,0,sizeof vis);
        for (int j=1;j<=m;j++)
            if (maxl-l[j]>n||l[j]>maxl)
                vis[j]=1;
        ans=std::min(dijkstra(),ans);
    }
    printf("%d\n",ans);
}
