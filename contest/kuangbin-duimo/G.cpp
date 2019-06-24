#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
const int maxn=2e6+100;
const int maxm=1<<22;
typedef long long ll;
struct query{
    int l,r,id,block;
    bool operator<(const query &a)const{
        return block==a.block?r<a.r:block<a.block;
    }
}q[maxn];
ll cnt[maxm],a[maxn],ans[maxn],ans1,k,block_size;
int n,m;
void add(ll x){
    ans1+=cnt[x^k];
    ++cnt[x];
}
void del(ll x){
    --cnt[x];
    ans1-=cnt[x^k];
}
void solve(){
    int l=0,r=0;
    std::sort(q+1,q+m+1);
    cnt[0]=1;
    for (int i=1;i<=m;i++){
        while(l<q[i].l) del(a[l++]);
        while(l>q[i].l) add(a[--l]);
        while(r<q[i].r) add(a[++r]);
        while(r>q[i].r) del(a[r--]);
        ans[q[i].id]=ans1;
    }
}
int main(){
    scanf("%d%d%I64d",&n,&m,&k);
    block_size=(int)sqrt(n);
    for (int i=1;i<=n;i++){
        scanf("%I64d",a+i);
        a[i]^=a[i-1];
    }
    for (int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        q[i].l=x,q[i].r=y;
        q[i].id=i,q[i].block=x/block_size;
    }
    solve();
    for (int i=1;i<=m;i++)
        printf("%I64d\n",ans[i]);
    return 0;
}
