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
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define maxn 1000100
#define m0(a) memset(a,0,sizeof a)
using namespace std;
const int d[5][2]={0,0,0,1,0,-1,1,0,-1,0};
typedef long long ll;
struct pp{
    char dir;
    int t,v;
}pao[101][101];
struct node{
    int x,y,step;
    node(){}
    node(int a,int b,int c){
        x=a,y=b,step=c;
    }
};
bool vis[101][101][1005];
int a[101][101];
int m,n,k,num;
inline int judge(int x,int y){
    if (x<0||x>m||y<0||y>n||a[x][y])
        return 0;
    return 1;
}
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' | c > '9')c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        putchar(x / y + 48);
        x %= y;
    }
}
void bfs(){
    queue<node> que;
    m0(vis);
    vis[0][0][0]=1;
    que.push(node(0,0,0));
    while(!que.empty()){
        node now=que.front();
        que.pop();
        rep(i,0,5){
            int tx=now.x+d[i][0];
            int ty=now.y+d[i][1];
            if (!judge(tx,ty))
                continue;
            node nt;
            nt.x=tx,nt.y=ty,nt.step=now.step+1;
            if (nt.step>num)
                continue;
            if (vis[tx][ty][nt.step])
                continue;
            int flag=1;
            rep(j,tx+1,m+1){//往南找北方向的炮塔
                if (a[j][ty]==1&&pao[j][ty].dir=='N'){
                    int dis=j-tx;
                    if (dis%pao[j][ty].v)//不是整数倍的话就不可能在整点到达当前点
                        break;
                    int tmp=nt.step-dis/pao[j][ty].v;
                    if (tmp<0)
                        break;
                    if (tmp%pao[j][ty].t==0){
                        flag=0;
                        break;
                    }
                }
                if (a[j][ty]==1)
                    break;
            }
            if (!flag)
                continue;
            for (int j=tx-1;j>=0;j--){
                if (a[j][ty]==1&&pao[j][ty].dir=='S'){
                    int dis=tx-j;
                    if (dis%pao[j][ty].v)
                        break;
                    int tmp=nt.step-dis/pao[j][ty].v;
                    if (tmp<0)
                        break;
                    if (tmp%pao[j][ty].t==0){
                        flag=0;
                        break;
                    }
                }
                if (a[j][ty]==1)
                    break;
            }
            if (!flag)
                continue;
            rep(j,ty+1,n+1){//往东找西方向的炮塔
                if (a[tx][j]==1&&pao[tx][j].dir=='W'){
                    int dis=j-ty;
                    if (dis%pao[tx][j].v)
                        break;
                    int tmp=nt.step-dis/pao[tx][j].v;
                    if (tmp<0)
                        break;
                    if (tmp%pao[tx][j].t==0){
                        flag=0;
                        break;
                    }
                }
                if (a[tx][j]==1)
                    break;
            }
            if (!flag)
                continue;
            for (int j=ty-1;j>=0;j--){
                if (a[tx][j]==1&&pao[tx][j].dir=='E'){
                    int dis=ty-j;
                    if (dis%pao[tx][j].v)
                        break;
                    int tmp=nt.step-dis/pao[tx][j].v;
                    if (tmp<0)
                        break;
                    if (tmp%pao[tx][j].t==0){
                        flag=0;
                        break;
                    }
                }
                if (a[tx][j]==1)
                    break;
            }
            if (!flag)
                continue;
            vis[tx][ty][nt.step]=1;
            if (tx==m&&ty==n&&nt.step<=num){
                write(nt.step);
                putchar('\n');
                return;
            }
            que.push(nt);
        }
    }
    printf("Bad luck!\n");
}
int main(){
    while(~scanf("%d%d%d%d",&m,&n,&k,&num)){
        m0(a);
        memset(pao,-1,sizeof pao);
        rep(i,0,k){
            int x,y,t,v;
            char ch[2];
            scanf("%s",ch);
            t=read(),v=read(),x=read(),y=read();
            //printf("%s%d%d%d%d\n",ch,t,v,x,y);
            a[x][y]=1;
            pao[x][y].dir=ch[0],pao[x][y].t=t,pao[x][y].v=v;
        }
        bfs();
    }
    return 0;
}


