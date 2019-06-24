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
#define maxn 500050
#define m0(a) memset(a,0,sizeof a)
using namespace std;
struct node{
    int x,y,w;
    int operator<(const node &a)const{
        return w<a.w;
    }
}edge[maxn];
int n,m,fa[100010];
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
void write(ll x) {
    ll y = 10, len = 1;
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
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void kruskal(){
    sort(edge,edge+m);
    ll ans=0;
    rep(i,0,m){
        int x=edge[i].x;
        int y=edge[i].y;
        x=find(x),y=find(y);
        if (x!=y)
            fa[x]=y,ans+=edge[i].w;
    }
    write(ans);
}
int main(){
    n=read(),m=read();
    rep(i,0,m){
        int x,y,z;
        x=read(),y=read(),z=read();
        edge[i].x=x;
        edge[i].y=y;
        edge[i].w=z;
    }
    rep(i,1,n+1)
        fa[i]=i;
    kruskal();
    return 0;
}

