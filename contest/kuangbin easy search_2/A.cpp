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
#define maxn 400050
#define m0(a) memset(a,0,sizeof a)
using namespace std;
const int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const char ss[10]="udlr";
const int fac[]={1,1,2,6,24,120,720,5040,40320};
int n,m;
int vis[maxn];
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
struct node{
    int a[3][3];
    int x,y;
    int h,g,has;
    int operator<(const node&v)const{
        return h+g>v.h+v.g;
    }
};
struct pr{
    int pre;
    char op;
}p[maxn];
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
int get_h(const node&t){
    int ans=0;
    rep(i,0,3)
        rep(j,0,3){
            if (t.a[i][j]==0)
                continue;
            ans+=abs(i-(t.a[i][j]-1)/3)+abs(j-(t.a[i][j]-1)%3);
        }
    return ans;
}
inline int judge(int x,int y){
    if (x>-1&&x<3&&y>-1&&y<3)
        return 1;
    return 0;
}
void print(int has){
    if (p[has].pre==-1)
        return;
    print(p[has].pre);
    printf("%c",p[has].op);
}
void A_star(node t){
    priority_queue<node> que;
    t.has=get_has(t);
    t.h=get_h(t);
    t.g=0;
    node to;
    rep(i,0,3)
        rep(j,0,3)
            to.a[i][j]=i*3+j+1;
    to.a[2][2]=0;
    int to_has=get_has(to);
    //printf("%d %d\n",t.has,to_has);
    if (t.has==to_has){
        //putchar('\n');
        printf("\n");
        return;
    }
    p[t.has].pre=-1;
    vis[t.has]=1;
    que.push(t);
    //printf("%d\n",to_has);
    while(!que.empty()){
        node now=que.top();
        //printf("%d\n",now.has);
        que.pop();
        rep(i,0,4){
            int tx=now.x+d[i][0];
            int ty=now.y+d[i][1];
            node nt=now;
            if (!judge(tx,ty))
                continue;
            swap(nt.a[now.x][now.y],nt.a[tx][ty]),nt.x=tx,nt.y=ty;
            int has=get_has(nt);
            if (vis[has])
                continue;
            vis[has]=1;
            nt.g=now.g+1;
            nt.h=get_h(nt);
            nt.has=has;
            p[has].pre=now.has;
            p[has].op=ss[i];
            if (has==to_has){
                print(has);
                printf("\n");
                return;
            }
            que.push(nt);
        }
    }
}
int main(){
    char s[30];
    while(gets(s)){
        m0(vis);
        node st;
        int b[9];
        int len=strlen(s);
        int j=0;
        rep(i,0,len){
            if (s[i]==' ')
                continue;
            if (s[i]=='x')
                st.a[j/3][j%3]=0,st.x=j/3,st.y=j%3;
            else
                st.a[j/3][j%3]=s[i]-'0';
            ++j;
        }
        int k=0,f=0;
        rep(i,0,3)
            rep(j,0,3)
                b[k++]=st.a[i][j];
        int i;
        for(i=0,k=0;i<9;i++)
        {
            if(st.a[i/3][i%3]==0)continue;
            for(j=0;j<i;j++)
            {
                if(st.a[j/3][j%3]==0)continue;
                if(st.a[j/3][j%3]>st.a[i/3][i%3])k++;
            }
        }
        //printf("%d\n",k);
        if (k&1)
            printf("unsolvable\n");
        else
            A_star(st);
    }
    return 0;
}
