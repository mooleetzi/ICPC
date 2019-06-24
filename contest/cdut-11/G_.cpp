#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
const int maxVet=1e3+10;
const int maxEdge=1e5+10;
struct node{
    int to,next,w;
}edge1[maxEdge],edge2[maxEdge];
int head1[maxVet],d1[maxVet],d2[maxVet],head2[maxVet];
int n,m,x;
void spfa(int s,int d[],node edge[],int head[]){
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
int main(){
    while(~scanf("%d%d%d",&n,&m,&x)){
        memset(head1,-1,sizeof head1);
        memset(head2,-1,sizeof head2);
        memset(d1,0,sizeof d1);
        memset(d2,0,sizeof d2);
        for (int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            edge1[i].to=y;
            edge1[i].w=z;
            edge1[i].next=head1[x];
            head1[x]=i;
            edge2[i].to=x;
            edge2[i].next=head2[y];
            edge2[i].w=z;
            head2[y]=i;
        }
        spfa(x,d1,edge1,head1);
        spfa(x,d2,edge2,head2);
        int ans=-1;
        for (int i=1;i<=n;i++){
            if (d1[i]+d2[i]>ans)
                ans=d1[i]+d2[i];
        }
        printf("%d\n",ans);
    }
}
