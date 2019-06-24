#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
struct node{
    int l,r,sum,change;
}tree[maxn<<3];
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
        tree[now].sum=1;
        return;
    }
    int m=(l+r)>>1;
    build(now<<1,l,m);
    build(now<<1|1,m+1,r);
    pushup(now);
}
void update(int now,int L,int R,int C){
    int l=tree[now].l;
    int r=tree[now].r;
    pushdown(now,r-l+1);
    int m=(l+r)>>1;
    if (l>=L&r<=R){
        tree[now].change=C;
        tree[now].sum=(r-l+1)*C;
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
int sum(int now,int L,int R){
    int l=tree[now].l;
    int r=tree[now].r;
    int m=(l+r)>>1;
    pushdown(now,r-l+1);
    if (l>=L&&r<=R)
        return tree[now].sum;
    if (m<L)
        return sum(now<<1|1,L,R);
    else if (m>=R)
        return sum(now<<1,L,R);
    else
        return sum(now<<1,L,m)+sum(now<<1|1,m+1,R);
}
int main(){
    int t;
    scanf("%d",&t);
    int q=0;
    while(q<t){
        int n,m;
        scanf("%d",&n);
        build(1,1,n);
        scanf("%d",&m);
        for (int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            update(1,a,b,c);
        }
        printf("Case %d: The total value of the hook is %d.\n",++q,sum(1,1,n));
    }
    return 0;
}
