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
typedef long long ll;
char op[9][maxn];
int pre[9][maxn];
const int fac[]={1,1,2,6,24,120,720,5040,40320};
const int d[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
const char ss[10]="dlru";
int vis[maxn],has;
struct node{
    int a[3][3];
    int x,y;
    node(){}
    node(char *s)
    {
        int i,j;
        int xx = 0,yy = 0;
        for(i = 0; i<strlen(s); i++)
        {
            a[xx][yy] = s[i]-'0';
            if(s[i] == 'X')
            {
                x = xx;
                y = yy;
            }
            yy++;
            if(yy == 3)
            {
                xx++;
                yy = 0;
            }
        }
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
int get_has(const node&t){
    int b[9];
    int k=0;
    rep(i,0,3)
        rep(j,0,3)
            b[k++]=t.a[i][j];
    int ans=0;
    rep(i,1,9){
        int now=0;
        rep(j,0,i)
            if (b[j]>b[i])
                ++now;
        ans+=fac[i]*now;
    }
    return ans;
}
void bfs(int p,node st){
    queue<node> que;
    //printf("%d\n",st.has);
    memset(pre[p],-1,sizeof pre[p]);
    m0(vis);
    int shas=get_has(st);
    vis[shas]=1;
    printf("%d\n",shas);
    que.push(st);
    while(!que.empty()){
        node now=que.front();
        que.pop();
        int now_has=get_has(now);
        //printf("%d\n",now_has);
        rep(i,0,4){
            node nt=now;
            int tx=now.x+d[i][0];
            int ty=now.y+d[i][1];
            if (tx<0||tx>2||ty<0||ty>2)
                continue;
            swap(nt.a[now.x][now.y],nt.a[tx][ty]);
            int has=get_has(nt);
            if (vis[has])
                continue;
            nt.x=tx,nt.y=ty;
            vis[has]=1;
            pre[p][has]=now_has;
            op[p][has]=ss[i];
            que.push(nt);
        }
    }
    return;
}
int main(){
    int T,q=0;
    T=read();
    m0(vis);
    node s;
    s=node("X12345678");bfs(0,s);
    s=node("1X2345678");bfs(1,s);
    s=node("12X345678");bfs(2,s);
    s=node("123X45678");bfs(3,s);
    s=node("1234X5678");bfs(4,s);
    s=node("12345X678");bfs(5,s);
    s=node("123456X78");bfs(6,s);
    s=node("1234567X8");bfs(7,s);
    s=node("12345678X");bfs(8,s);
    while(q<T){
        char s1[10];
        gets(s1);
        int num[10];
        m0(num);
        int pos;
        int j=0;
        rep(i,0,9){
            if (s1[i]=='X')
                pos=i;
            else
                num[s1[i]-'0']=j++;
        }
        gets(s1);
        rep(i,0,9)
            if (s1[i]=='X')
                continue;
            else
                s1[i]=num[s1[i]-'0']+'1';
        //cout<<s1<<"\n";
        s=node(s1);
        int has=get_has(s);
        printf("%d\n",has);
        string ans="";
        while(pre[pos][has]!=-1){
            ans+=op[pos][has];
            has=pre[pos][has];
            //printf("%d\n",has);
        }
        printf("Case %d: %d\n",++q,ans.length());
        for (int i=ans.length()-1;i>-1;i--)
            putchar(ans[i]);
        putchar('\n');
    }
    return 0;
}


