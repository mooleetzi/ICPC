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
int a[25][3],m;
typedef long long ll;
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
int p[25],tot=0,vis[25];
void print(){
    printf("%d:  ",++tot);
    rep(i,0,21)
        printf("%d%c",p[i],i==20?'\n':' ');
}
void dfs(int now,int step){
    p[step]=now;
    if (now==m&&step>=20){
        print();
        return;
    }
    if (vis[now])
        return;
    vis[now]=1;
    rep(i,0,3)
        dfs(a[now][i],step+1);
    vis[now]=0;
}
int main(){
    memset(a,-1,sizeof a);
    rep(i,1,21){
        int x,y,z;
        x=read();y=read();z=read();
        a[i][0]=x,a[i][1]=y,a[i][2]=z;
    }
    rep(i,1,21)
        sort(a[i],a[i]+3);
    m=read();
    while(m){
        tot=0;
        m0(vis);
        dfs(m,0);
        m=read();
    }
    return 0;
}


