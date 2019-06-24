//dijkstra求所有路径中的最小权值的最大值
//题意：一条路径里的所有权值中最小值m，ans为max{m}
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int ma[1005][1005];
int d[1005];
int vis[1005];
int n,m;
void dijkstra(){
    memset(vis,0,sizeof vis);
    for (int i=1;i<=n;i++){
        d[i]=ma[1][i];
        vis[i]=0;
    }
    d[1]=0;
    for (int i=1;i<=n;i++){
        int u,maxn=-1;
        for (int j=1;j<=n;j++)
        if (!vis[j]&&d[j]>maxn){
            u=j;
            maxn=d[j];
        }
        vis[u]=1;
        for (int j=1;j<=n;j++)
            if (!vis[j]&&d[j]<min(d[u],ma[u][j]))
                d[j]=min(d[u],ma[u][j]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    int t,q=0;
    cin>>t;
    while(q<t){
        cin>>n>>m;
        memset(ma,0,sizeof ma);
        for (int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            ma[x][y]=z;
            ma[y][x]=z;
        }
        dijkstra();
        cout<<"Scenario #"<<++q<<":\n"<<d[n]<<"\n\n";
    }
    return 0;
}
