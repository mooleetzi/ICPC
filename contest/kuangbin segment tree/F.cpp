#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
const int maxn=8001;
struct node{
    int l,r,val,change;
}tree[maxn<<2];
int a[maxn];
set<int> ss;
void pushup(int now){
    if (tree[now<<1].val!=tree[now<<1|1].val)
        tree[now].val=-1;
    else
        tree[now].val=tree[now<<1].val;
}
void pushdown(int now){
    if (tree[now].change){
        tree[now<<1].change=tree[now<<1|1].change=tree[now].change;
        tree[now<<1].val=tree[now<<1|1].val=tree[now].change;
        tree[now].change=0;
    }
}
void build(int now,int l,int r){
    tree[now].l=l;
    tree[now].r=r;
    tree[now].change=0;
    tree[now].val=-1;
    if (l==r)
        return;
    int m=(l+r)>>1;
    build(now<<1,l,m);
    build(now<<1|1,m+1,r);
    pushup(now);
}
void update(int now,int L,int R,int C){
    int l=tree[now].l;
    int r=tree[now].r;
    if (tree[now].val==C)
        return;
    if (l>=L&&r<=R){
        tree[now].val=C;
        tree[now].change=C;
        return;
    }
    int m=(l+r)>>1;
    pushdown(now);
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
void query(int now){
    int l=tree[now].l;
    int r=tree[now].r;
    if (tree[now].val!=-1){
        ss.insert(tree[now].val);
        a[tree[now].val]++;
        return;
    }
    if (l==r) return;
    pushdown(now);
    //pushup(now);
    query(now<<1);
    query(now<<1|1);
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        build(1,1,maxn);
        ss.clear();
        memset(a,0,sizeof a);
        for (int i=0;i<n;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if (a+1>b)
                continue;
            update(1,a+1,b,c);
        }
        query(1);
        set<int>::iterator s;
        for (s=ss.begin();s!=ss.end();s++)
            printf("%d %d\n",*s,a[*s]);
        printf("\n");
    }
    return 0;
}
