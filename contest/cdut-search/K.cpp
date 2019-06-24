#include<iostream>
#include<cstring>
#include<queue>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof a)
#define maxn 10010
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int a[5][5];
struct node{
    int x,y,pre;
};
node que[maxn];
int fa[maxn];
int vis[5][5];
int l,r;
void print();
void bfs();
int main(){
    ios::sync_with_stdio(false);
    mt(vis,0);
    rep(i,0,5)
        rep(j,0,5)
            cin>>a[i][j];
    cout<<"(0, 0)\n";
    bfs();
    print();
    return 0;
}
void bfs(){
    que[0].x=0;
    que[0].y=0;
    que[0].pre=-1;
    vis[0][0]=1;
    l=0;r=1;
    while(l<r){
        int x,y;
        rep(i,0,4){
            x=que[l].x+dx[i];
            y=que[l].y+dy[i];
            if (x>-1&&x<5&&y>-1&&y<5&&!vis[x][y]&&!a[x][y]){
                que[r].x=x;
                que[r].y=y;
                que[r].pre=l;
                vis[x][y]=1;
                if (x==4&&y==4){
                    print();
                    return;
                }
                r++;
            }
        }
        l++;//队首元素出队
    }
    return;
}
void print(){
    int xx[maxn],yy[maxn];
    mt(xx,0);
    mt(yy,0);
    int i=0;
    while(que[r].pre!=-1){
        xx[i]=que[r].x;
        yy[i++]=que[r].y;
        r=que[r].pre;
    }
    for (int j=i-1;j>-1;j--)
        cout<<"("<<xx[j]<<", "<<yy[j]<<")\n";
    return;
}
