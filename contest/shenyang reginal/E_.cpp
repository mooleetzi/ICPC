#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=100010;
int n,m,dis[maxn];
int tot,head1[maxn],head2[maxn];
bool flag[maxn];
struct edge
{
    int to;
    int w;
    int next;
}e[maxn*2],e2[maxn*2];
struct node
{
    int f;//f=g+dis dis表示当前点到终点的最短路径，即之前的预处理
    int g;//g表示到当前点的路径长度
    int from;
    bool operator < (node a)const
    {
        if(a.f==f)
        return g>a.g;//重载 小的在前面
        return f>a.f;
    }
};
void add_edge(int u,int v,int w)
{
    tot++;
    e[tot].to=v;
    e[tot].w=w;
    e[tot].next=head1[u];
    head1[u]=tot;
    e2[tot].to=u;//建反图
    e2[tot].w=w;
    e2[tot].next=head2[v];
    head2[v]=tot;
}
void spfa(int t)//反图预处理dis
{
    for(int i=1;i<=n;i++)
    dis[i]=maxn;
    dis[t]=0;
    queue<int> q;
    q.push(t);
    flag[t]=1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();flag[v]=0;
        for(int i=head2[v];~i;i=e2[i].next)
        if(dis[e2[i].to]>dis[v]+e2[i].w)
        {
            dis[e2[i].to]=dis[v]+e2[i].w;
            if(!flag[e2[i].to])
            {
                q.push(e2[i].to);
                flag[e2[i].to]=1;
            }
        }
    }
}
int a_star(int s,int t,int k)
{
    if(s==t) return 0;
    if(dis[s]==maxn) return -1;
    priority_queue<node> q;
    int cnt=0;
    node tmp,to;
    tmp.from=s;
    tmp.g=0;
    tmp.f=tmp.g+dis[tmp.from];
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        if(tmp.from==t) cnt++;
        if(cnt==k) return tmp.g;
        for(int i=head1[tmp.from];~i;i=e[i].next)
        {
            to.from=e[i].to;
            to.g=tmp.g+e[i].w;
            to.f=to.g+dis[to.from];
            q.push(to);
        }
    }
    return -1;
}
int main::time;
int main()
{
    ios::sync_with_stdio(false);
    int x,y,z,s,t,k;
    while(cin>>n>>m){
        memset(head1,-1,sizeof head1);
        memset(head2,-1,sizeof head2);
        //int time;
        cin>>s>>t>>k>>time;
        for(int i=1;i<=m;i++){
            cin>>x>>y>>z;
            add_edge(x,y,z);
            //add_edge(y,x,z);
        }
        spfa(t);
        int ans=a_star(s,t,k);
        //cout<<ans<<"\n";
        if (ans<=time&&ans!=-1)
            cout<<"yareyaredawa\n";
        else
            cout<<"Whitesnake!\n";
    }
    return 0;
}
