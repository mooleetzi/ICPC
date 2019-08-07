#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int x[maxn],vis[maxn],y[maxn];
int a[maxn][maxn];
int n,m,k;
int find(int u){
    for (int i=1;i<=m;i++)
    if (a[u][i]&&!vis[i]){
        vis[i]=1;
        if (y[i]==-1||find(y[i])){
            y[i]=u;
            x[u]=i;
            return 1;
        }
    }
    return 0;
}
int main(){
    int ans=0;
    ios::sync_with_stdio(false);
    while(cin>>k&&k){
        cin>>n>>m;
        ans=0;
        memset(a,0,sizeof a);
        memset(x,-1,sizeof x);
        memset(y,-1,sizeof y);
        for (int i=1;i<=k;i++){
            int x,y;
            cin>>x>>y;
            a[x][y]=1;
        }
        for (int i=1;i<=n;i++){
            if (x[i]==-1){
                memset(vis,0,sizeof vis);
                ans+=find(i);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
