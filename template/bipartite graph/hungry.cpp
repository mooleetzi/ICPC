#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int x[maxn],vis[maxn],y[maxn],head[maxn];
int a[maxn][maxn];
struct node{
    int to,next;
}edge[maxn];
int n,m,k;
int find(int u){
    for (int i=head[u];~i;i=edge[i].next)
    if (!vis[edge[i].to]){
        int v=edge[i].to;
        vis[v]=1;
        if (y[v]==-1||find(y[v])){
            y[v]=u;
            x[u]=v;
            return 1;
        }
    }
    return 0;
}
void add(int x,int y){
    static int tot=0;
    edge[tot].to=y;
    edge[tot].next=head[x];
    head[x]=tot++;
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
        memset(head,-1,sizeof head);
        for (int i=1;i<=k;i++){
            int x,y;
            cin>>x>>y;
            add(x,y);
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
