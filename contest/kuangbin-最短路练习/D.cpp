#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
struct edg{
    int to,next,w;
}edge[100000+100];
int head[1005],inq[1005];
int n,m,x;
int spfa(int s,int t){
    int d[1005];
    memset(d,0x3f,sizeof d);
    memset(inq,0,sizeof(inq));
    queue<int> que;
    d[s]=0;
    que.push(s);
    inq[s]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        inq[u]=0;
        for (int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            if (d[v]>d[u]+edge[i].w){
                d[v]=d[u]+edge[i].w;
                if (!inq[v]){
                    que.push(v);
                    inq[v]=1;
                }
            }
        }
    }
    return d[t];
}
int main(){
    ios::sync_with_stdio(false);
    memset(head,-1,sizeof(head));
    cin>>n>>m>>x;
    for (int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edge[i].to=y;
        edge[i].w=z;
        edge[i].next=head[x];
        head[x]=i;
    }
    int maxn=-1;
    for (int i=1;i<=n;i++){
        if (i==x)
            continue;
        int a=spfa(i,x);
        int b=spfa(x,i);
        if (a+b>maxn)
            maxn=a+b;
    }
    cout<<maxn<<"\n";
    return 0;
}
