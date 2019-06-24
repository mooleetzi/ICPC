#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn=1e6+10;
int block_size;
typedef long long ll;
struct nod{
    int l,r,bl,br,id,t;
    nod(){}
    nod(int a,int b,int c,int d){
        l=a,r=b,id=c,t=d;
        bl=l/block_size,br=r/block_size;
    }
    bool operator<(const nod &a)const{
        if (bl==a.bl){
            if (br==a.br)
                return t<a.t;
            return br<a.br;
        }
        return bl<a.bl;
    }
}q[maxn];
struct no{
    int pos,val;
}c[maxn];
int ans[maxn];
int cnum;
int num;
int ans1;
int a[maxn],vis[maxn];
ll sum[maxn];
//fenwick tree
void update(int x,int v){
    while(x<maxn){
        sum[x]+=v;
        x+=lowbit(x);
    }
}
ll query(int x){
    ll ans=0;
    while(x){
        ans+=sum[x];
        x-=lowbit(x);
    }
    return ans;
}


//modui
void add(int x){
    if (vis[x]==0)
        ans1++;
    vis[x]++;
}
void del(int x){
    if (--vis[x]==0)
        ans1--;
}
void change(int now,int i){

}
int main(){
    ios::sync_with_stdio(false);
    int n,m,x;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>x;
        update(i+1,x);
    }
    for (int i=1;i<=n;i++)
        cout<<query(i)<<"\n";
//    block_size=(int)sqrt(n);
//    for (int i=1;i<=n;i++)
//        cin>>a[i];
//    for (int i=1;i<=m;i++){
//        string s;
//        cin>>s;
//        if (s[0]=='Q'){
//            int x,y;
//            std::cin>>x>>y;
//            q[++num].l=x;
//            q[num].r=y;
//            q[num].id=num;
//            q[num].bl=x/block_size;
//            q[num].br=y/block_size;
//            q[num].t=cnum;
//        }
//        else{
//            int x,y;
//            cin>>x>>y;
//            c[++cnum].pos=x;
//            c[cnum].val=y;
//        }
//    }
//    sort(q+1,q+1+num);
//    int l=1,r=0,now=0;
//    for (int i=1;i<=num;i++){
//        while(l<q[i].l) del(a[l++]);
//        while(r<q[i].r) add(a[++r]);
//        while(l>q[i].l) add(a[--l]);
//        while(r>q[i].r) del(a[r--]);
//        while(now<q[i].t) change(++now,i);
//        while(now>q[i].t) change(now--,i);
//        ans[q[i].id]=ans1;
//    }
//    for (int i=1;i<=num;i++)
//        cout<<ans[i]<<"\n";
    return 0;
}
