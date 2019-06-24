#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof(a))
#define maxn 1005
using namespace std;
int ma[2006][2005];
int d[2005];
int edge_num,vet_num;
void dijkstra();
int main(){
    int t,q=0;
    ios::sync_with_stdio(false);
    scanf("%d",&t);
    while(q<t){
        cin>>vet_num>>edge_num;
        mt(ma,0);
        rep(i,0,edge_num){
            int x,y,z;
            cin>>x>>y>>z;
            ma[x][y]=z;
            ma[y][x]=z;
        }
        dijkstra();
        cout<<"Scenario #"<<++q<<":\n"<<d[vet_num]<<"\n\n";
    }
    return 0;
}
void dijkstra(){
    int vis[maxn];
    for (int i=2;i<=vet_num;i++){
        d[i]=ma[1][i];
        vis[i]=0;
    }
    int u,mins;
    d[1]=0;
    for (int i=1;i<=vet_num;i++){
        mins=-1;
        for (int j=1;j<=vet_num;j++)
        if (!vis[j]&&d[j]>mins){
            u=j;
            mins=d[j];
        }
        vis[u]=1;
        for (int j=1;j<=vet_num;j++)
            if (!vis[j]&&d[j]<min(d[u],ma[u][j]))
                d[j]=min(d[u],ma[u][j]);
    }
    return;
}
