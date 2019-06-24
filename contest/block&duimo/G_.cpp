#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
const int maxn=1e4+10;
int ans[maxn],a[maxn],*vis;
int block_size,unum,qnum,ans1;
struct query{
    int l,r,bl,br,t,id;
    int operator<(const query &a)const{
        if (bl==a.bl)
            return br==a.br?br<a.br:t<a.t;
        return bl<a.bl;
    }
}q[maxn];
struct upt{
    int pos,val;
}u[maxn/10];
void add(int x){
    if (++vis[x]==1)
        ++ans1;
}
void del(int x){
    if (--vis[x]==0)
        --ans1;
}
void change(int now,int i){
    if (u[now].pos>=q[i].l&&u[now].pos<=q[i].r){
        add(u[now].val);
        del(a[u[now].pos]);
    }
    std::swap(a[u[now].pos],u[now].val);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vis=new int[1000010];
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    block_size=(int)sqrt(n);
    for (int i=0;i<m;i++){
        char ch[2];
        int x,y;
        scanf("%s%d%d",ch,&x,&y);
        if (ch[0]=='Q')
            q[++qnum]=query{x,y,x/block_size,y/block_size,unum,qnum};
        else if (ch[0]=='R')
            u[++unum]=upt{x,y};
    }
    std::sort(q+1,q+1+qnum);
    int l=0,r=0,now=0;
    for (int i=1;i<=qnum;i++){
        while(l>q[i].l) add(a[--l]);
        while(l<q[i].l) del(a[l++]);
        while(r>q[i].r) del(a[r--]);
        while(r<q[i].r) add(a[++r]);
        while(now<q[i].t) change(++now,i);
        while(now>q[i].t) change(now--,i);
        ans[q[i].id]=ans1;
    }
    for (int i=1;i<=qnum;i++)
        printf("%d\n",ans[i]);
    return 0;
}
