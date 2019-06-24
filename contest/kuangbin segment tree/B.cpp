#include<bits/stdc++.h>
using namespace std;
const int maxn=200001;
struct node{
    int l,r,ma;
}tree[maxn<<2];
int a[maxn];
void push(int now){
    tree[now].ma=max(tree[now<<1].ma,tree[now<<1|1].ma);
}
void build(int now,int l,int r){
    tree[now].l=l;
    tree[now].r=r;
    if (l==r){
        scanf("%d",&tree[now].ma);
//        tree[now].ma=a[l];
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
        return;
    }
    int m=(l+r)>>1;
    if (m<L)
        update(now<<1|1,L,C);
    else
        update(now<<1,L,C);
    push(now);
}
int query(int now,int L,int R){
    int l=tree[now].l;
    int r=tree[now].r;
    if (l==L&&r==R)
        return tree[now].ma;
    int m=(l+r)>>1;
    if (m<L)
        return query(now<<1|1,L,R);
    else if (m>=R)
        return query(now<<1,L,R);
    else
        return max(query(now<<1,L,m),query(now<<1|1,m+1,R));
}
int main(){
    //ios::sync_with_stdio(false);
    int n,m;
//    cin>>n>>m;
    while(~scanf("%d%d",&n,&m)){
//        for (int i=1;i<=n;i++)
//            scanf("%d",a+i);
        build(1,1,n);
        int l,r;
        char ch;
        getchar();
        for (int i=0;i<m;i++){
            scanf("%c%d%d",&ch,&l,&r);
            //cout<<ch<<" "<<l<<" "<<r<<"\n";
            if (ch=='Q')
                cout<<query(1,l,r)<<"\n";
            else if (ch=='U')
                update(1,l,r);
            getchar();
        }
    }
    return 0;
}
