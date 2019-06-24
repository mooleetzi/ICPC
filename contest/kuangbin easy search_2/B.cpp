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
#define maxn 1001000
#define m0(a) memset(a,0,sizeof a)
using namespace std;
typedef long long ll;
const int fac[]={1,1,2,6,24,120,720,5040,40320};
const int d[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
const char ss[10]="dlru";
int vis[maxn],has;
struct pr{
    int pre;
    char op;
}p[maxn];
struct node{
    int a[3][3];
    int g,h,has;
    int x,y;
    node(){
        m0(a);
    }
    int operator<(const node&t)const{
        return g+h>t.g+t.h;
    }
};
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
int get_xy(node t,int c){
    rep(i,0,3)
        rep(j,0,3)
            if (t.a[i][j]==c)
                return i*3+j+1;
}
int get_has(node t){
    int ans=0,b[9],k=0;
    rep(i,0,3)
        rep(j,0,3)
            b[k++]=t.a[i][j];
    rep(i,0,9){
        k=0;
        if(b[i]==40)
            continue;
        rep(j,0,i){
            if (b[j]==40)
                continue;
            if (b[j]>b[i])
                ++k;
        }
        ans+=k*fac[i];
    }
    return ans;
}
int get_h(node now,node en){
    int ans=0;
    rep(i,0,3)
        rep(j,0,3){
            if (now.a[i][j]==40) continue;
            int p=get_xy(en,now.a[i][j]);
            ans+=abs(i-(p-1)/3)+abs(j-(p-1)%3);
        }
    return ans;
}
void print(int has){
    if (p[has].pre==-1)
        return;
    print(p[has].pre);
    putchar(p[has].op);
}
int n,m;
int bfs(node &st,node &en){
    m0(vis);
    st.g=0,st.h=get_h(st,en);
    st.has=get_has(st),en.has=get_has(en);
    p[st.has].pre=-1;vis[st.has]=1;
    if (st.has==en.has)
        return 0;
    priority_queue<node> que;
    que.push(st);
    while(!que.empty()){
        node now=que.top();
        que.pop();
        rep(i,0,4){
            int tx=now.x+d[i][0];
            int ty=now.y+d[i][1];
            if (tx<0||tx>=3||ty>=3||ty<0)
                continue;
            node nt=now;
            swap(nt.a[now.x][now.y],nt.a[tx][ty]);
            nt.has=get_has(nt);
            int k=nt.has;
            if (vis[k])
                continue;
            nt.x=tx,nt.y=ty;
            nt.g=now.g+1,nt.h=get_h(nt,en);
            p[k].pre=now.has;
            p[k].op=ss[i];
            if (k==en.has)
                return nt.g;
            vis[k]=1;
            que.push(nt);
        }
    }
}
void init(char s[],node &t){
    rep(i,0,9){
        if (s[i]=='X'){
            t.a[i/3][i%3]=0;
            t.x=i/3,t.y=i%3;
        }
        else{
            t.a[i/3][i%3]=s[i]-'0';
        }
    }
}
int main(){
    int T,q=0;
    T=read();
    while(q<T){
        char s1[100],s2[100];
        gets(s1),gets(s2);
        node st,en;
        init(s1,st);
        init(s2,en);
        int ans=bfs(st,en);
        printf("Case %d: %d\n",++q,ans);
        if (ans){
            print(en.has);
            printf("\n");
        }
    }
    return 0;
}


