#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#define mem(a,x) memset(a,x,sizeof a)
#define rep(i,x,y) for (int i=x;i<y;i++)
#define rp(i,x) for (int i=head[x];~i;i=edge[i].next)
using namespace std;
const int maxn=20;
typedef long long ll;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int n,m,cnt,mn=0x3f3f3f3f;
int op[maxn][maxn],a[maxn][maxn],t[maxn][maxn];
inline int judge(int x,int y){
    if (x>=n||x<0||y>=m||y<0)
        return 0;
    return 1;
}
void flip(int x,int y){
    op[x][y]=1,t[x][y]^=1;++cnt;
    rep(i,0,4){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if (judge(tx,ty))
            t[tx][ty]^=1;
    }
}
int solve(int x){
    cnt=0;
    memcpy(t,a,sizeof a);
    for (int i=0;i<m;i++)
        if ((1<<(m-1-i))&x){
            flip(0,i);
        }
    rep(i,1,n)
        rep(j,0,m)
            if (t[i-1][j]){
                flip(i,j);
            }
    for (int i=0;i<m;i++)
        if (t[n-1][i])
            return 0;
    return 1;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
    int ans=-1,sum;
    sum=0x3f3f3f;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for (int i=0;i<(1<<m);i++)
        if (solve(i)&&cnt<sum)
            ans=i,sum=cnt;
    mem(op,0);
    if (ans>-1){
        solve(ans);
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                printf("%d%c",op[i][j],j==m-1?'\n':' ');
    }
    else
        puts("IMPOSSIBLE\n");
    }
    return 0;
}
