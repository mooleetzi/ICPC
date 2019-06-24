#include<queue>
#include<iostream>
#include<cstring>
#define rep(i,x,y) for (int i=x;i<y;i++)
using namespace std;
const int dx[]={0,0,0,0,-1,1};
const int dy[]={1,0,-1,0,0,0};
const int dz[]={0,-1,0,1,0,0};
struct node{
    int x,y,z;
    int step;
    node(){}
    node(int a,int b,int c,int d):x(a),y(b),z(c),step(d){}
};
node que[50000];
char ma[40][40][40];
int vis[40][40][40];
int n,m,k;
int sx,sy,sz;
int ans=0;
void bfs();
int main(){
    while(cin>>n>>m>>k&&(m+n+k)){
        ans=0;
        rep(i,0,n)
            rep(j,0,m){
                cin>>ma[i][j];
                rep(q,0,k)
                    if (ma[i][j][q]=='S'){
                        sx=i;
                        sy=j;
                        sz=q;
                    }
            }
        memset(vis,0,sizeof vis);
        bfs();
        if (ans==-1)
            cout<<"Trapped!\n";
        else
            cout<<"Escaped in "<<ans<<" minute(s).\n";
    }
    return 0;
}
void bfs(){
    int head,tail;
    head=0;
    tail=1;
    que[0].x=sx;
    que[0].y=sy;
    que[0].z=sz;
    que[0].step=0;
    vis[sx][sy][sz]=1;
    while(head<tail){
        int x,y,z;
        rep(i,0,6){
            x=que[head].x+dx[i];
            y=que[head].y+dy[i];
            z=que[head].z+dz[i];
            if (x>-1&&x<n&&y>-1&&y<m&&z>-1&&z<k&&!vis[x][y][z]&&ma[x][y][z]!='#'){
                que[tail].x=x;
                que[tail].y=y;
                que[tail].z=z;
                que[tail].step=que[head].step+1;
                tail++;
                vis[x][y][z]=1;
                if (ma[x][y][z]=='E'){
                    ans=que[head].step+1;
                    return;
                }
            }
        }
        head++;
    }
    ans=-1;
    return;
}
