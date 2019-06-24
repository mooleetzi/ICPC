#include<bits/stdc++.h>
using namespace std;
const int maxn=250;
int n,m,a,b;
int ans;
int to[maxn];
int vis[maxn];
struct node{
    int u,dis;
};
void bfs(){
    queue<node> que;
    que.push(node{0,0});
    vis[0]=1;
    while(!que.empty()){
        node now=que.front();
        que.pop();
        node next;
        next.u=now.u+1;
        next.dis=now.dis+1;
        if (next.u==m){
            ans=next.dis;
            return;
        }
        if (!vis[next.u]){
            vis[next.u]=1;
            que.push(next);
        }
        next.u=now.u-1;
        if (next.u==m){
            ans=next.dis;
            return;
        }
        if (!vis[next.u]){
            vis[next.u]=1;
            que.push(next);
        }
        if (to[now.u]!=-1){
            next.u=to[now.u];
            if (next.u==m){
                ans=next.dis;
                return;
            }
            if (!vis[next.u]){
                vis[next.u]=1;
                que.push(next);
            }
        }
    }
}
int main(){
    memset(to,-1,sizeof to);
    memset(vis,0,sizeof vis);
    scanf("%d%d",&m,&n);
    for (int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        to[x]=y;
    }
    bfs();
    printf("%d\n",ans);
    return 0;
}
