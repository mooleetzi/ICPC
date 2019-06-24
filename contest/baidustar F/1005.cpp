#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
#include<stack>
#include<map>
#include<cmath>
#include<string>
#include<vector>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define max(x,y) (x>y)?x:y
#define maxn 30
#define m0(a) memset(a,0,sizeof a)
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int n,m,k;
int a[maxn][maxn];
int vis[maxn],inq[maxn][maxn];
set<int> ss[420];
struct node{
    int x,y,dis,c;
    int operator<(const node &a)const{
        return dis==a.dis?c>a.c:dis<a.dis;
    }
};
inline int judge(int x,int y){
    if (x>-1&&x<n&&y>-1&&y<m)
        return 1;
    return 0;
}
int bfs(node s){
    priority_queue<node> que;
    while(!que.empty())
        que.pop();
    que.push(s);
    inq[s.x][s.y]=1;
    if (k==1&&a[s.x][s.y]>0)
        return 0;
    while(!que.empty()){
        node now=que.top();
        que.pop();
        --inq[now.x][now.y];
        rep(i,0,4){
            node next;
            int tx=now.x+dx[i];
            int ty=now.y+dy[i];
            if (judge(tx,ty)&&a[tx][ty]>-1){
                if (ss[tx*n+ty].size()<ss[now.x*n+ty)
                    ss[tx*n+ty]=ss[now.x*n+ty];
                else
                if (ss[tx*n+ty].size()>=k)
                        return now.dis+1;
            }
                if (inq[tx][ty]>n)
                    return inf;
                next.x=tx;
                next.y=ty;
                next.dis=now.dis+1;
                que.push(next),inq[tx][ty]++;
            }
        }
    }
    return inf;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(a,-1,sizeof a);
        scanf("%d%d%d",&n,&m,&k);
        rep(i,0,n)
            rep(j,0,m)
                scanf("%d",&a[i][j]);
        int ans=inf;
        rep(i,0,n)
            rep(j,0,m)
                if (a[i][j]>-1){
                    rep(k,0,i*j)
                    ss[i].clear();
                    m0(inq);
                    m0(vis);
                    node s;
                    s.x=i;
                    s.y=j;
                    s.dis=0;
                    if (a[i][j])
                        ss[i*n+j].insert(a[i][j]);
                    if (a[i][j]==0)
                        s.c=0;
                    vis[a[i][j]]=1;
//                    printf("%d\n",bfs(s));
                    ans=min(ans,bfs(s));
                }
        if (ans==inf)
            printf("-1\n");
        else
        printf("%d\n",ans);
    }
}
