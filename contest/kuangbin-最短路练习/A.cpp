//甘霖娘，数据范围有毒吧兄弟
//提上说2k,加到2e6才过
#include<iostream>
#include<queue>
#include<cstring>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof(a))
#define rep2(i,x) for (int i=head[x];~i;i=edge[i].next)
using namespace std;
const int max_vet=1e3+10;
const int max_edge=2e6+10;
struct edg{
    int next,to,w;
}edge[max_edge];
struct node{
    int x,w;
    node(){}
    node(int a,int b):x(a),w(b){}
    bool operator<(const node &q)const{
        return w>q.w;
    }
};
int head[max_vet],d[max_vet],vis[max_vet];
void dijkstra(int,int);
void add(int,int,int);
int edge_num,vet_num,cnt,ans;
int main(){
    ios::sync_with_stdio(false);
    mt(head,-1);
    mt(d,0x3f);
    mt(vis,0);
    cin>>edge_num>>vet_num;
    rep(i,0,edge_num){
        int x,y,z;
        cin>>x>>y>>z;
        add(x,y,z);
        add(y,x,z);
    }
    dijkstra(vet_num,1);
    return 0;
}
void add(int x,int y,int z){
    edge[cnt].to=y;
    edge[cnt].w=z;
    edge[cnt].next=head[x];
    head[x]=cnt++;
}
void dijkstra(int s,int t){
    priority_queue<node> que;
    que.push(node(s,0));
    d[s]=0;
    while(!que.empty()){
        node now=que.top();
        que.pop();
        if(vis[now.x]) continue;
        vis[now.x]=1;
        rep2(i,now.x){
            int y=edge[i].to;
            int z=edge[i].w;
            if (d[y]>now.w+z){
                d[y]=now.w+z;
                que.push(node(y,d[y]));
            }
        }
    }
    cout<<d[t];
}
