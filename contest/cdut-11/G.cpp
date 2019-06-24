#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
const int maxVet=1e3+10;
const int maxEdge=1e5+10;
struct node{
    int to,next,w;
}edge[maxEdge];
int head[maxVet],d1[maxVet],d2[maxVet];
int n,m,x;
void spfa(int s,int d[]){
    int inq[maxVet],dis[maxVet];
    memset(inq,0,sizeof inq);
    inq[s]=1;
    std::queue<int> que;
    while(!que.empty()){
        que.pop();
    }
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    que.push(s);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        inq[u]=0;
        for (int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            if (dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                if (!inq[v]){
                    inq[v]++;
                    que.push(v);
                }
            }
        }
    }
    for (int i=1;i<=n;i++)
        d[i]=dis[i];
}
int spfa(int s,int t){
    int inq[maxVet],dis[maxVet];
    memset(inq,0,sizeof inq);
    inq[s]=1;
    std::queue<int> que;
    while(!que.empty()){
        que.pop();
    }
    memset(dis,0x3f,sizeof dis);
    dis[s]=0;
    que.push(s);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        inq[u]=0;
        for (int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            if (dis[v]>dis[u]+edge[i].w){
                dis[v]=dis[u]+edge[i].w;
                if (!inq[v]){
                    inq[v]++;
                    que.push(v);
                }
            }
        }
    }
    return dis[t];
}
int main(){
    while(~scanf("%d%d%d",&n,&m,&x)){
        memset(head,-1,sizeof head);
        memset(d1,0,sizeof d1);
        memset(d2,0,sizeof d2);
        for (int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            edge[i].to=y;
            edge[i].w=z;
            edge[i].next=head[x];
            head[x]=i;
        }
        spfa(x,d1);
//        spfa(n,d2);
        int ans=-1;
        for (int i=1;i<=n;i++){
            int q=spfa(i,x);
            if (i!=x&&d1[i]+q>ans)
                ans=d1[i]+q;
        }
        printf("%d\n",ans);
    }
}
