#include<iostream>
#include<cstring>
#include<queue>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof a)
using namespace std;
const int maxn=2e5+10;
struct node{
    int step,x;
    node(){}
    node(int a,int b):x(a),step(b){}
};
int vis[maxn];
void bfs();
int ans=0;
int s,e;
int main(){
    ios::sync_with_stdio(false);
    cin>>s>>e;
    bfs();
    cout<<ans;
    return 0;
}
void bfs(){
    mt(vis,0);
    vis[s]=1;
    queue<node> que;
    que.push(node(s,0));
    while(!que.empty()){
        node now=que.front();
        que.pop();
        if (now.x+1>-1&&now.x+1<maxn&&!vis[now.x+1]){
            que.push(node(now.x+1,now.step+1));
            vis[now.x+1]=1;
            if (now.x+1==e){
                ans=now.step+1;
                return;
            }
        }
        if (now.x-1>-1&&now.x-1<maxn&&!vis[now.x-1]){
            que.push(node(now.x-1,now.step+1));
            vis[now.x-1]=1;
            if (now.x-1==e){
                ans=now.step+1;
                return;
            }
        }
        if (2*now.x>-1&&2*now.x<maxn&&!vis[2*now.x]){
            que.push(node(2*now.x,now.step+1));
            vis[2*now.x]=1;
            if (2*now.x==e){
                ans=now.step+1;
                return;
            }
        }
    }
}
