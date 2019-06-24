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
typedef long long ll;
const int d[4][2]={1,0,0,-1,0,1,-1,0};
const char s[]="dlru";
int fac[10];
int vis[maxn],pre[10][maxn];
char op[10][maxn];
struct node{
    int x,y;
    int a[3][3];
    node(){}
    node(const char p[]){
        int xx=0,yy=0;
        rep(i,0,strlen(p)){
            if (p[i]=='X')
                a[xx][yy]=p[i]-'0',x=xx,y=yy;
            else
                a[xx][yy]=p[i]-'0';
            ++yy;
            if (yy==3){
                yy=0;
                ++xx;
            }
        }
    }
};
int get_has(const node &t){
    int b[9],k=0;
    rep(i,0,3)
        rep(j,0,3)
            b[k++]=t.a[i][j];
    int ans=0;
    rep(i,1,9){
        k=0;
        rep(j,0,i){
            if (b[j]>b[i])
                k++;
        }
        ans+=fac[i]*k;
    }
    return ans;
}
inline judge(int x,int y){
    if (x>2||x<0||y>2||y<0)
        return 0;
    return 1;
}
void bfs(int p,node st){
    m0(vis);
    memset(pre[p],-1,sizeof pre[p]);
    vis[get_has(st)]=1;
    queue<node> que;
    que.push(st);
    //printf("%d\n",get_has(st));
    while(!que.empty()){
        node now=que.front();
        que.pop();
        int now_has=get_has(now);
        rep(i,0,4){
            node nt=now;
            int tx=now.x+d[i][0];
            int ty=now.y+d[i][1];
            if (!judge(tx,ty))
                continue;
            swap(nt.a[now.x][now.y],nt.a[tx][ty]);
            int has=get_has(nt);
            if (vis[has])
                continue;
            vis[has]=1;
            nt.x=tx,nt.y=ty;
            pre[p][has]=now_has;
            op[p][has]=s[i];
            que.push(nt);
        }
    }
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
int main(){
    fac[0]=1;
    rep(i,1,10)
        fac[i]=i*fac[i-1];
    int T;
    node st;
    st=node("X12345678");bfs(0,st);
    st=node("1X2345678");bfs(1,st);
    st=node("12X345678");bfs(2,st);
    st=node("123X45678");bfs(3,st);
    st=node("1234X5678");bfs(4,st);
    st=node("12345X678");bfs(5,st);
    st=node("123456X78");bfs(6,st);
    st=node("1234567X8");bfs(7,st);
    st=node("12345678X");bfs(8,st);
    T=read();
    rep(i,1,T+1){
        char s1[10];
        gets(s1);
        int num[10],pos,k=0;
        m0(num);
        rep(j,0,9)
            if (s1[j]=='X')
                pos=j;
            else
                num[s1[j]-'0']=k++;
        gets(s1);
        rep(j,0,9)
            if (s1[j]=='X')
                continue;
            else
                s1[j]=num[s1[j]-'0']+'1';
        int has=get_has(node(s1));
        //printf("%d\n",has);
        string ans="";
        while(pre[pos][has]!=-1){
            ans+=op[pos][has];
            has=pre[pos][has];
        }
        printf("Case %d: %d\n",i,ans.length());
        for (int j=ans.length()-1;j>-1;j--)
            putchar(ans[j]);
        putchar('\n');
    }
    return 0;
}


