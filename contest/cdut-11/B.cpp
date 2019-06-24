/*
一遍prim求最小生成树
标记后再求次小生成树
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define rep(i,x,y) for (int i=x;i<y;i++)
using namespace std;
const int maxn=10010;
const int maxnode=110;
typedef long long ll;
int n,m;
int path[maxnode][maxnode],dis[maxnode],pre[maxnode],a[maxnode][maxnode],vis[maxnode],uesd[maxnode][maxnode];
int prim(){
    memset(path,0,sizeof path);
    memset(dis,0x3f,sizeof dis);
    memset(uesd,0,sizeof uesd);
    memset(vis,0,sizeof vis);
    int ans=0;
    for (int i=1;i<=n;i++)
        dis[i]=a[1][i],pre[i]=1;
    vis[1]=1;
    for (int i=0;i<n-1;i++){
        int u=-1,mins=0x3f3f3f3f;
        for (int j=1;j<=n;j++){
            if (!vis[j]&&dis[j]<mins){
                u=j;
                mins=dis[j];
            }
        }
        vis[u]=1;
        if (u==-1)
            return -1;
        ans+=mins;
        uesd[u][pre[u]]=uesd[pre[u]][u]=1;
        for (int j=1;j<=n;j++){
            if (vis[j]&&j!=u){
                path[j][u]=path[u][j]=max(path[j][pre[u]],dis[u]);
            }
            else if (!vis[j]){
                if (dis[j]>a[u][j]){
                    dis[j]=a[u][j];
                    pre[j]=u;
                }
            }
        }
    }
    return ans;
}
void s_prim(){
    int ans1=prim();
    if (ans1==-1)
        printf("Not Unique!\n");
    else{
        int ans2=0x3f3f3f3f;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (i!=j&&!uesd[i][j]){
                ans2=min(ans2,ans1-path[i][j]+a[i][j]);
            }
        if (ans2==ans1)
            printf("Not Unique!\n");
        else
            printf("%d\n",ans1);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(a,0x3f,sizeof a);
        for (int i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x][y]=z;
            a[y][x]=z;
        }
        s_prim();
    }
    return 0;
}
