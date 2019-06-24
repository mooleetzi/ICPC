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
#define maxn 110
#define m0(a) memset(a,0,sizeof a)
#define inf 0x3f3f3f3f
using namespace std;
int a[maxn][maxn],b[maxn][maxn];
int n,m,s,t,k;
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
int main(){
    n=read(),m=read(),s=read(),t=read(),k=read();
    memset(a,0x3f,sizeof a);
    memset(b,0x3f,sizeof b);
    rep(i,0,m){
        int x,y,z;
        x=read(),y=read(),z=read();
        a[x][y]=a[y][x]=z;
        b[x][y]=b[y][x]=2;
    }
    rep(k,0,n){
        rep(i,0,n)
            rep(j,0,n)
                if(a[i][k]+a[k][j]<a[i][j])
                    a[i][j]=a[i][k]+a[k][j],b[i][j]=b[i][k]+b[k][j];
    }
    if (b[s][t]!=inf&&b[s][t]>=k)
        write(a[s][t]);
    return 0;
}


