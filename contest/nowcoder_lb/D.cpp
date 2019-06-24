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
#define maxn 1000010
#define m0(a) memset(a,0,sizeof a)
using namespace std;
typedef long long ll;
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')c = getchar();
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
struct node{
    int ch;
    int sum;
}q[maxn];
int last[128];
int main(){
    int n,m;
    n=read(),m=read();
    m0(last);
    rep(i,1,n+1){
        q[i].ch=getchar();
        q[i].sum=q[last[q[i].ch]].sum+1;
        last[q[i].ch]=i;
    }
    getchar();
    rep(i,0,m){
        int x=read();
        write(q[x].sum);
        putchar('\n');
    }
    return 0;
}

