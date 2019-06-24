#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
struct node{
    int l,r,sum,change;
}tree[maxn<<3];
int ans=0;
typedef long long ll;
void pushup(int now){
    tree[now].sum=tree[now<<1].sum+tree[now<<1|1].sum;
}
void pushdown(int now,int len){
    if (tree[now].change){
        tree[now<<1].change=tree[now].change;
        tree[now<<1|1].change=tree[now].change;
        tree[now<<1].sum=(len-(len>>1))*tree[now].change;
        tree[now<<1|1].sum=(len>>1)*tree[now].change;
        tree[now].change=0;
    }
}
void build(int now,int l,int r){
    tree[now].l=l;
    tree[now].r=r;
    tree[now].change=0;
    if (l==r){
        tree[now].sum=0;
        return;
    }
    int m=(l+r)>>1;
    build(now<<1,l,m);
    build(now<<1|1,++m,r);
}
void update(int now,int L,int R,int C){
    int l=tree[now].l;
    int r=tree[now].r;
    pushdown(now,r-l+1);
    int m=(l+r)>>1;
    if (l>=L&r<=R){
        tree[now].change=C;
        tree[now].sum+=(r-l+1)*C;
        return;
    }
    if (l==r) return;
    if (m<L)
        update(now<<1|1,L,R,C);
    else if (m>=R)
        update(now<<1,L,R,C);
    else{
        update(now<<1,L,m,C);
        update(now<<1|1,m+1,R,C);
    }
    pushup(now);
}
void query(int rt,int L,int R,ll C){
    int l=tree[rt].l;
    int r=tree[rt].r;
    pushdown(rt,r-l+1);
    if (l>=L&&r<=R){
        //printf("%d %d %ld\n",l,r,tree[rt].sum);
        if (tree[rt].sum<=C){
            ans+=(r-l)<<1|1;
            return;
        }
        if (l==r)
            return;
        int m=(l+r)>>1;
        query(rt<<1,l,m,C);
        query(rt<<1|1,++m,r,C);
    }
    else{
        int mid=(l+r)>>1;
        if (mid<L)
            query(rt<<1|1,L,R,C);
        else if (mid>=R)
            query(rt<<1,L,R,C);
        else{
            query(rt<<1,L,mid,C);
            query(rt<<1|1,++mid,R,C);
        }
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
        build(1,1,n);
        ans=0;
        int l,r,op;
        ll c;
        for (int i=0;i<q;++i){
            scanf("%d%d%d%lld",&op,&l,&r,&c);
            if (op==1)
                update(1,l,r,c);
            else{
                ans=0;
                query(1,l,r,c);
                printf("%d\n",ans);
            }
        }
    return 0;
}
