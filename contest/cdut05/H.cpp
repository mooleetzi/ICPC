#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof(a))
#define maxn 400
using namespace std;
const int dx[]={0,1,0,-1,0};
const int dy[]={1,0,-1,0,0};
int ma[maxn+10][maxn+10],ans=0,vis[maxn+10][maxn+10];
struct node{
    int x,y,step;
    node(){}
    node(int a,int b,int c):x(a),y(b),step(c){}
};
void bfs(){
    if (ma[0][0]==0x3f3f3f3f){
        ans=0;
        return;
    }
    mt(vis,0);
    queue<node> que;
    vis[0][0]=1;
    que.push(node(0,0,0));
    while(!que.empty()){
        node now=que.front();
        que.pop();
        int x,y;
        rep(i,0,4){
            x=now.x+dx[i];
            y=now.y+dy[i];
            if (x>-1&&y<maxn&&y>-1&&x<maxn&&!vis[x][y]&&now.step+1<ma[x][y]){
                vis[x][y]=1;
                que.push(node(x,y,now.step+1));
                if (ma[x][y]==0x3f3f3f3f){
                    ans=now.step+1;
                    return;
                }
            }
        }
    }
    ans=-1;
    return;
}
int main(){
    int m;
    while(scanf("%d",&m)==1){
        mt(ma,0x3f);
        rep(i,0,m){
            int x,y,t,tx,ty;
            scanf("%d%d%d",&x,&y,&t);
            ma[x][y]=min(ma[x][y],t);
            rep(j,0,5){
                tx=x+dx[j];
                ty=y+dy[j];
                if (tx>-1&&tx<maxn&&ty>-1&&ty<maxn)
                    ma[tx][ty]=min(ma[tx][ty],t);
            }
        }
        bfs();
        printf("%d\n",ans);
    }
    return 0;
}

