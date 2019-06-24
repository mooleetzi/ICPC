#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=550;
const int inf=0x3f3f3f3f;
int dis[maxn],a[maxn][maxn],pre[maxn],c[maxn],d[maxn],vis[maxn],w[maxn];
int n,m,s,t;
void dijk(){
    dis[s]=0;
    c[s]=d[s];
    for (int i=0;i<n;i++){
        int minx=inf;
        int u=-1;
        for (int j=0;j<n;j++)
            if (!vis[j]&&dis[j]<minx){
                minx=dis[j];
                u=j;
            }
        if (u==-1)
            break;
        vis[u]=1;
        for (int j=0;j<n;j++)
            if (!vis[j]&&a[u][j]!=inf){
                if (dis[j]>dis[u]+a[u][j]){
                    dis[j]=dis[u]+a[u][j];
                    c[j]=c[u]+d[j];
                    pre[j]=u;
                    w[j]=1;
                }
                else if (dis[j]==dis[u]+a[u][j]&&c[j]<c[u]+d[j]){
                    c[j]=c[u]+d[j];
                    pre[j]=u;
                    w[j]++;
                }
            }
    }
    vector<int> ans;
    printf("%d %d\n",w[t],c[t]);
    while(t!=-1){
        ans.emplace_back(t);
        t=pre[t];
    }
    for (int i=ans.size()-1;i>0;i--)
        printf("%d ",ans[i]);
    printf("%d",ans.front());
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for (int i=0;i<=n;i++){
        pre[i]=-1;
        dis[i]=inf;
        c[i]=-inf;
        vis[i]=0;
        w[i]=0;
        for (int j=0;j<=n;j++)
            a[i][j]=inf;
    }
    for (int i=0;i<n;i++)
        scanf("%d",&d[i]);
    for (int i=0;i<m;i++){
        int x,b,c;
        scanf("%d%d%d",&x,&b,&c);
        if (a[x][b]>c)
            a[x][b]=a[b][x]=c;
    }
    dijk();
    return 0;
}
