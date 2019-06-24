//·Ö²ã×î¶ÌÂ·
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=5e6+10;
struct node{
    int to,next,w;
}edge[maxn];
int head[maxn],inq[maxn];
ll d[maxn];
ll ans;
int tot;
struct nd{
    int u,dis;
    nd(){}
    nd(int a,int b){
        u=a,dis=b;
    }
    int operator<(const nd&a)const{
        return dis>a.dis;
    }
};
void dijkstra(int s){
    memset(d,0x3f,sizeof d);
    priority_queue<nd> que;
    que.push(nd(s,0));
    d[s]=0;
    memset(inq,0,sizeof inq);
    while(!que.empty()){
        nd now=que.top();
        que.pop();
        int u=now.u;
        if (inq[u])
            continue;
        inq[u]=1;
        for (int i=head[u];~i;i=edge[i].next){
            int v=edge[i].to;
            if (!inq[v]&&d[v]>edge[i].w+d[u]){
                d[v]=edge[i].w+d[u];
                que.push(nd(v,d[v]));
            }
        }
    }
}
void add(int x,int y,int z){
    edge[tot].to=y;
    edge[tot].next=head[x];
    edge[tot].w=z;
    head[x]=tot++;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(head,-1,sizeof head);
        int n,m,k;
        tot=0;
        scanf("%d%d%d",&n,&m,&k);
        for (int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            for (int j=0;j<=k;j++){
                add(x+j*n,y+j*n,z);
                if (j!=k)
                    add(x+j*n,y+(j+1)*n,0);
            }
        }
        dijkstra(1);
        ll ans=0x3f3f3f3f;
        for (int i=0;i<=k;i++)
            ans=min(ans,d[n+i*n]);
        printf("%lld\n",ans);
    }
    return 0;
}
