//spfa不用node，直接记录点，只需要用d数组记录距离就行
//dijkstra因为要用到距离选取点（堆）,故需要node
#include<iostream>
#include<queue>
#include<cstring>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof(a))
#define rep2(i,x) for (int i=head[x];~i;i=edge[i].next)
using namespace std;
const int max_vet=1e3+100;
const int max_edge=2e6+200;
struct edg{
    int to,w,next;
}edge[max_edge];
int head[max_vet],inq[max_vet],d[max_vet],cnt;
void spfa(int,int);
void add(int,int,int);
int main(){
    ios::sync_with_stdio(false);
    int t,n;
    mt(head,-1);
    mt(inq,0);
    mt(d,0x3f);
    cin>>t>>n;
    rep(i,0,t){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    spfa(n,1);
    return 0;
}
void add(int a,int b,int z){
    edge[cnt].to=b;
    edge[cnt].w=z;
    edge[cnt].next=head[a];
    head[a]=cnt++;
}
void spfa(int s,int t){
    queue<int> que;
    que.push(s);
    d[s]=0;
    inq[s]=1;
    while(!que.empty()){
        int now=que.front();
        que.pop();
        inq[now]=0;
        rep2(i,now){
            int y=edge[i].to;
            int z=edge[i].w;
            if (d[y]>d[now]+z){
                d[y]=d[now]+z;
                if (!inq[y]){
                    que.push(y);
                    inq[y]=1;
                }
            }
        }
    }
    cout<<d[t];
}

