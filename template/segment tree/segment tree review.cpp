#include<bits/stdc++.h>
using namespace std;
const int maxn=25001;
struct node{
    int l,r,mi,ma,sum;
}tree[maxn<<2];
int a[maxn];
void push(int now){
    tree[now].ma=max(tree[now<<1].ma,tree[now<<1|1].ma);
    tree[now].mi=min(tree[now<<1].mi,tree[now<<1|1].mi);
    tree[now].sum=tree[now<<1].sum+tree[now<<1|1].sum;
}
void build(int now,int l,int r){
    tree[now].l=l;
    tree[now].r=r;
    if (l==r){
        tree[now].mi=tree[now].ma=tree[now].sum=a[l];
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
        tree[now].mi=tree[now].ma=tree[now].sum=C;
        return;
    }
    int m=(l+r)>>1;
    if (m<L)
        update(now<<1|1,L,C);
    else
        update(now<<1,L,C);
    push(now);
}
int sum(int now,int L,int R){
    int l=tree[now].l;
    int r=tree[now].r;
    if (L==l&&R==r)
        return tree[now].sum;
    int m=(l+r)>>1;
    if (m>=R)
        return sum(now<<1,L,R);
    else if (m<L)
        return sum(now<<1|1,L,R);
    else
        return (sum(now<<1,L,m)+sum(now<<1|1,m+1,R));
}
int maxs(int now,int L,int R){
    int l=tree[now].l;
    int r=tree[now].r;
    if (l==L&&r==R)
        return tree[now].ma;
    int m=(l+r)>>1;
    if (m>=R)
        return maxs(now<<1,L,R);
    else if (m<L)
        return maxs(now<<1|1,L,R);
    else
        return max(maxs(now<<1,L,m),maxs(now<<1|1,m+1,R));
}
int mins(int now,int L,int R){
    int l=tree[now].l;
    int r=tree[now].r;
    if (l==L&&r==R)
        return tree[now].mi;
    int m=(l+r)>>1;
    if (m>=R)
        return mins(now<<1,L,R);
    else if (m<L)
        return mins(now<<1|1,L,R);
    else
        return min(mins(now<<1|1,m+1,R),mins(now<<1,L,m));
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",a+i+1);
    build(1,1,n);
    int L,R,C;
    while(~scanf("%d%d%d",&L,&R,&C)){//输入C=-1查询 C！=-1更新
        if (C==-1){
            printf("%d ",mins(1,L,R));
            printf("%d ",maxs(1,L,R));
            printf("%d\n",sum(1,L,R));
        }
//            printf("%d %d %d\n",mins(1,L,R),maxs(1,L,R),sum(1,L,R));
        else
            update(1,L,C);
    }
    return 0;
}
