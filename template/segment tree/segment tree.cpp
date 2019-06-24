/*
线段树模板
区间最值，区间和
单点更新
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=25001;
struct node{
    int l,r,ma,sum,mi;
}tree[maxn<<2];
int a[maxn];
void push(int now){
    tree[now].sum=tree[now<<1].sum+tree[now<<1|1].sum;
    tree[now].ma=max(tree[now<<1].ma,tree[now<<1|1].ma);
    tree[now].mi=min(tree[now<<1].mi,tree[now<<1|1].mi);
}
void build(int now,int l,int r){//注意的是建树和更新点以后都需要重新push
    tree[now].l=l;
    tree[now].r=r;
    cout<<l<<" "<<r<<"\n";
    if (l==r){
        tree[now].ma=a[l];
        tree[now].sum=a[l];
        tree[now].mi=a[l];
        return;
    }
    int m=(l+r)>>1;
    build(now<<1,l,m);
    build(now<<1|1,m+1,r);
    push(now);
}
void update(int now,int L,int C){
    int l=tree[now].l;
    int r=tree[now].r;
    if (l==r){
        tree[now].ma=C;
        tree[now].sum=C;
        tree[now].mi=C;
        return;
    }
    int m=(l+r)>>1;
    if (m<L)//只需遍历右区间的情况
        update(now<<1|1,L,C);
    else
        update(now<<1,L,C);
    push(now);
}
int sum(int now,int L,int R){
    int l=tree[now].l;
    int r=tree[now].r;
    if (l==L&&r==R)
        return tree[now].sum;
    int ans=0;
    int m=(l+r)>>1;
    if (m<L)//只需遍历右区间的情况
        ans+=sum(now<<1|1,L,R);
    else if (m>=R)//只需遍历左区间的情况
        ans+=sum(now<<1,L,R);
    else ans+=(sum(now<<1,L,m)+sum(now<<1|1,m+1,R));
}
int maxnumb(int now,int L,int R){
    int l=tree[now].l;
    int r=tree[now].r;
    if (l==L&&r==R)
        return tree[now].ma;
    int m=(l+r)>>1;
    if (m<L)
        return maxnumb(now<<1|1,L,R);
    else if (m>=R)
        return maxnumb(now<<1,L,R);
    else return(max(maxnumb(now<<1,L,m),maxnumb(now<<1|1,m+1,R)));
}
int minnumb(int now,int L,int R){
    int l=tree[now].l;
    int r=tree[now].r;
    if (l==L&&r==R)
        return tree[now].mi;
    int m=(l+r)>>1;
    if (m<L)
        return minnumb(now<<1|1,L,R);
    else if (m>=R)
        return minnumb(now<<1,L,R);
    else return(min(minnumb(now<<1,L,m),minnumb(now<<1|1,m+1,R)));
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",a+i);
    build(1,1,n);
    int L,R;
    update(1,6,8);//将a[6]值更新为8
    while(~scanf("%d%d",&L,&R)){
        printf("%d %d %d\n",sum(1,L,R),minnumb(1,L,R),maxnumb(1,L,R));
    }
    return 0;
}
