#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
typedef long long ll;
struct node{
    int l,r;
    ll xorr;
}tree[maxn*6];
void pushup(int rt){
    tree[rt].xorr=tree[rt<<1].xorr^tree[rt<<1|1].xorr;
}
void build(int rt,int l,int r){
    tree[rt].l=l;
    tree[rt].r=r;
    if (l==r){
        tree[rt].xorr=0;
        return;
    }
    int m=(l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt);
}
void update(int rt,int L,int C){
    int l=tree[rt].l;
    int r=tree[rt].r;
    if (l==r&&l==L){
        tree[rt].xorr^=C;
        return;
    }
    int m=(l+r)>>1;
    if (m<L)
        update(rt<<1|1,L,C);
    else
        update(rt<<1,L,C);
    pushup(rt);
}
ll query(int rt,int L,int R){
    int l=tree[rt].l;
    int r=tree[rt].r;
    if (l==L&&r==R)
        return tree[rt].xorr;
    int m=(l+r)>>1;
    if (m<L)
        return query(rt<<1|1,L,R);
    else if(m>=R)
        return query(rt<<1,L,R);

    else
        return max(query(rt<<1,L,m),query(rt<<1|1,m+1,R));
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,0,m);
    for (int i=0;i<n;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if (x==1)
            update(1,y,z);
        else{
            printf("%d\n",query(1,y,z));
        }
    }
//    for (int i=1;i<20;i++)
//        cout<<tree[i].xorr<<"\n";
    return 0;
}
