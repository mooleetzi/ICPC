#include<bits/stdc++.h>
#define long long int
using namespace std;
const int maxn=1e5+10;
const int maxm=1<<22;
int a[maxn],block_size;
struct node{
    int l,r,bl,id;
    node(){}
    node(int a,int b,int c){
        l=a,r=b,id=c;
        bl=l/block_size;
    }
    bool operator<(const node &a)const{
        return bl==a.bl?r<a.r:bl<a.bl;
    }
}q[maxn];
int n,m,k,ans1;
int ans[maxn],cnt[maxm];
void add(int x){
    ans1+=cnt[x^k];
    cnt[x]++;
}
void del(int x){
    --cnt[x];
    ans1-=cnt[x^k];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    block_size=(int)sqrt(n);
    for (int i=1;i<=n;i++)
        cin>>a[i],a[i]^=a[i-1];
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        q[i]=node(x-1,y,i);
    }
    sort(q+1,q+1+m);
    int l=0,r=0;
    cnt[0]=1;
    for (int i=1;i<=m;i++){
        while(l<q[i].l) del(a[l++]);
        while(r<q[i].r) add(a[++r]);
        while(l>q[i].l) add(a[--l]);
        while(r>q[i].r) del(a[r--]);
        ans[q[i].id]=ans1;
    }
    for (int i=1;i<=m;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
