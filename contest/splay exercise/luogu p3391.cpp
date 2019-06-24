#include<iostream>
using namespace std;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
int ch[maxn][2],size[maxn],val[maxn],tag[maxn],fa[maxn],a[maxn];
int tot,rt;
inline void pushdown(int x){
    if (x&&tag[x]){
        swap(ch[x][0],ch[x][1]);
        tag[ch[x][0]]^=1;
        tag[ch[x][1]]^=1;
        tag[x]=0;
    }
}
inline void pushup(int x){
    size[x]=1+size[ch[x][0]]+size[ch[x][1]];
}
int build(int l,int r,int f){//模拟线段树建树方式建立
    if (l>r)
        return 0;
    int now=++tot;
    int mid=(l+r)>>1;
    val[now]=a[mid];
    fa[now]=f;
    size[now]=1;
    ch[now][0]=build(l,mid-1,now);
    ch[now][1]=build(mid+1,r,now);
    pushup(now);
    return now;
}
inline int ws(int x){
    return ch[fa[x]][1]==x;
}
void print(int now){
    pushdown(now);
    if (ch[now][0])
        print(ch[now][0]);
    if (val[now]>0&&val[now]<inf)
        cout<<val[now]<<" ";
    if (ch[now][1])
        print(ch[now][1]);
}
inline void connect(int s,int f,int w){
    if (s)
        fa[s]=f;
    if (f)
        ch[f][w]=s;
}
void rot(int x){
    int f=fa[x];
    int ff=fa[f];
//    pushdown(x);
//    pushdown(f);
    int w=ws(x);
    int wf=ws(f);
    int tson=ch[x][w^1];
    connect(tson,f,w);
    connect(f,x,w^1);
    connect(x,ff,wf);
    pushup(f);
    pushup(x);
}
void splay(int x,int f){
    for (int ff;(ff=fa[x])!=f;rot(x))
        if (fa[ff]!=f)
            rot(ws(x)==ws(ff)?ff:x);
    if (!f)
        rt=x;
}
int kth(int x){
    int now=rt;
    while(x){
        pushdown(now);
        if (x<=size[ch[now][0]])
            now=ch[now][0];
        else{
            x-=size[ch[now][0]]+1;
            if (!x)
                break;
            now=ch[now][1];
        }
    }
    return now;
}
void reverse(int ll,int rr){
    int l=kth(ll-1);
    int r=kth(rr+1);
    splay(l,0);
    splay(r,l);
    tag[ch[ch[rt][1]][0]]^=1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        a[i+1]=i;
    a[1]=-inf;
    a[n+2]=inf;
    rt=build(1,n+2,0);
    for (int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        reverse(l+1,r+1);
    }
    print(rt);
    return 0;
}
