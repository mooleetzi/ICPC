#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=20020;
typedef long long ll;
struct node{
    int to,next;
}edge[maxn];
int head[maxn],ind[maxn],val[maxn];
int n,m;
void solve(){
    queue<int> que;
    while(!que.empty()){
        que.pop();
    }
    ll ans=0;
    for (int i=1;i<=n;i++)
        if (!ind[i])
            que.push(i),val[i]=888;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        ans+=val[u];
        n--;
        for (int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            if (--ind[v]==0){
                que.push(v);
                val[v]=val[u]+1;
            }
        }
    }
    if (!n)
        printf("%lld\n",ans);
    else
        printf("-1\n");
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(ind,0,sizeof ind);
        memset(head,-1,sizeof head);
        memset(val,0,sizeof val);
        for (int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            edge[i].to=x;
            edge[i].next=head[y];
            ind[x]++;
            head[y]=i;
        }
        solve();
    }
    return 0;
}
