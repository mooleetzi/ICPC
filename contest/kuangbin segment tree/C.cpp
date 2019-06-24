#include<cstdio>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
struct node{
    int l,r;
    ll add,sum;
}tree[maxn*6];//我也没搞懂为什么要6倍
void pushup(int now){
    tree[now].sum=tree[now<<1].sum+tree[now<<1|1].sum;
}
void pushdown(int now,ll len){
    if (tree[now].add){
        tree[now<<1].add+=tree[now].add;
        tree[now<<1|1].add+=tree[now].add;
        tree[now<<1].sum+=tree[now].add*(len-(len>>1));
        tree[now<<1|1].sum+=tree[now].add*(len>>1);
        tree[now].add=0;
    }
}
void build(int now,int l,int r){
    tree[now].l=l;
    tree[now].r=r;
    tree[now].add=0;
    tree[now].sum=0;
    if (l==r){
        //scanf("%lld",&tree[now].sum);
        return;
    }
    int m=(l+r)>>1;
    build(now<<1,l,m);
    build(now<<1|1,m+1,r);
    pushup(now);
}
void update(int now,int L,int R,ll C){
    int l=tree[now].l;
    int r=tree[now].r;
    pushdown(now,r-l+1);//在每一次update时，先向下更新子区间
    if (l==L&&r==R){
        tree[now].sum+=C*(ll)(r-l+1);
        tree[now].add=C;
        return;
    }
    if (l==r) return;
//    pushdown(now,r-l+1);
    int m=(l+r)>>1;
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
ll sum(int now,int L,int R){
    int l=tree[now].l;
    int r=tree[now].r;
    int m=(l+r)>>1;
    pushdown(now,r-l+1);
    if (l==L&&r==R)
        return tree[now].sum;
//    pushdown(now,r-l+1);
    if (m<L)
        return sum(now<<1|1,L,R);
    else if (m>=R)
        return sum(now<<1,L,R);
    else return sum(now<<1,L,m)+sum(now<<1|1,m+1,R);
}
int main(){
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        build(1,1,n);
        getchar();
        char ch;
        int a,b;
        ll c;
        for (int i=0;i<q;i++){
            scanf("%c",&ch);
            if (ch=='Q'){
                scanf("%d%d",&a,&b);
                printf("%lld\n",sum(1,a,b));
            }
            else if (ch=='C'){
                scanf("%d%d%lld",&a,&b,&c);
                update(1,a,b,c);
            }
            getchar();
        }
    }
    return 0;
}
