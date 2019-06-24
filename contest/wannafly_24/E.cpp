/*
线段树模板
区间最值，区间和
单点更新
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
struct node{
    int l,r,sum,num;
}tree[maxn<<2];
int a[maxn];
void push(int now){
    tree[now].sum=tree[now<<1].sum+tree[now<<1|1].sum;
}
void build(int now,int l,int r){//注意的是建树和更新点以后都需要重新push
    tree[now].l=l;
    tree[now].r=r;
    //cout<<l<<" "<<r<<"\n";
    if (l==r){
        char c;
        cin>>c;
        tree[now].num=c-'0';
        if (c=='1')
            tree[now].sum=1;
        else
            tree[now].sum=0;
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
        if (tree[now].num!=C){
            if (tree[now].num==1)
                tree[now].sum--;
            else
                tree[now].sum++;
            tree[now].num=C;
        }
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
    return  ans;
}
int main(){
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    build(1,1,n);
    int L,R;
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if (a==1)
            cout<<sum(1,b,c)<<"\n";
        else{
            update(1,b,c);
        }
    }
    return 0;
}
