#include<bits/stdc++.h>
using namespace std;
const int maxn=50010;
struct node{
    int to,w,next;
    node(){
        to=w=next=0;
    }
}edge[maxn];
int ind[maxn];
int head[maxn];
int dis[maxn];
int n,ans;
int inq[maxn];
void spfa(){
    int s;
    for (int i=1;i<=n;i++)
    if (ind[i]==0){
            s=i;
            break;
    }
    queue<int> que;
    inq[s]=1;
    que.push(s);
    dis[s]=0;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        inq[u]=0;
        for (int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            if (edge[i].w+dis[u]<dis[v]){
                dis[v]=edge[i].w+dis[u];
                if (!inq[v]){
                    inq[v]=1;
                    que.push(v);
                }
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    memset(head,-1,sizeof head);
    for (int i=1;i<=n;i++)
        dis[i]=0x3f3f3f3f;
    for (int i=0;i<n-1;i++){
        int x,y,z;
        scanf("%d%d%d",&y,&x,&z);
        edge[i].to=y;
        edge[i].next=head[x];
        edge[i].w=-z;
        head[x]=i;
        ind[y]++;
    }
    spfa();
    ans=-0x3f3f3f3f;
    for (int i=1;i<=n;i++)
        if (-dis[i]>ans)
            ans=-dis[i];
    printf("%d",ans);
    return 0;
}
