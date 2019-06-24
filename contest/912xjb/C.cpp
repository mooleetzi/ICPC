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
char a[maxn],b[maxn],vis[maxn];
int n;
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
    int index,w;
    int operator<(const node &a)const{
        return w>a.w;
    }
}c[maxn],d[maxn];
int main(){
    n=read();
    gets(a);
    gets(b);
    memset(vis,0,sizeof vis);
    for (int i=0;i<2*n;i++){
        c[i].index=i;
        d[i].index=i;
        if (a[i]=='U'&&b[i]=='U')
            c[i].w=4,d[i].w=4,a[i]='1',b[i]='1';
        else if (a[i]=='U')
            c[i].w=3,d[i].w=2,a[i]='1',b[i]='0';
        else if (b[i]=='U')
            c[i].w=2,d[i].w=3,b[i]='1',a[i]='0';
        else
            c[i].w=d[i].w=1,b[i]=a[i]='0';
    }
    sort(c,c+2*n);
    sort(d,d+2*n);
    string s1="",s2="";
    int c1=0,c2=0;
    for (int i=1;i<=2*n;i++){
        if (i&1){
            int f=1;
            int t=0;
            while(f){
                if (!vis[c[t].index]){
                    s1+=a[c[t].index];
                    f=0;
                    vis[c[t].index]=1;
                }
                ++t;
            }
        }
        else{
            int f=1;
            int t=0;
            while(f){
                if (!vis[d[t].index]){
                    s2+=b[d[t].index];
                    f=0;
                    vis[d[t].index]=1;
                }
                ++t;
            }
        }
    }
    if (s1>s2)
        printf("clccle trl!\n");
    else if (s1<s2)
        printf("sarlendy tql!\n");
    else
        printf("orz sarlendy!\n");
    return 0;
}
