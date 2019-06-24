#include<iostream>
using namespace std;
const int inf=2147483647;
const int maxn=5e4+10;
int fa[maxn],val[maxn],ch[maxn][2],cnt[maxn],size[maxn];
int rt,tot;
inline void connect(int s,int f,int w){
    if (s)
        fa[s]=f;
    if (f)
        ch[f][w]=s;
}
inline int ws(int x){
    return ch[fa[x]][1]==x;
}
inline void pushup(int x){
    size[x]=cnt[x]+size[ch[x][0]]+size[ch[x][1]];
}
inline void rot(int x){
    int f=fa[x];
    int ff=fa[f];
    int w=ws(x);
    int wf=ws(f);
    int tson=ch[x][w^1];
    connect(tson,f,w);
    connect(f,x,w^1);
    connect(x,ff,wf);
    pushup(f);
    pushup(x);
}
void splay(int x,int u){
    for (int f;(f=fa[x])!=u;rot(x))
        if (fa[f]!=u)
            rot(ws(x)==ws(f)?f:x);
    if (!u)
        rt=x;
}
void insert(int x){
    int now=rt;
    if (!now){
        ++tot;
        cnt[tot]=1;
        val[tot]=x;
        rt=tot;
        return;
    }
    while(1){
        if (val[now]==x)
            break;
        if (x>val[now]){
            if (!ch[now][1]){
                ++tot;
                val[tot]=x;
                connect(tot,now,1);
            }
            now=ch[now][1];
        }
        else{
            if (!ch[now][0]){
                ++tot;
                val[tot]=x;
                connect(tot,now,0);
            }
            now=ch[now][0];
        }
    }
    ++cnt[now];
    splay(now,0);
}
int main(){

}
