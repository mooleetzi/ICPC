#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int block_size;
int vis[maxn],a[10010],ans[10010];
struct node{
    int l,r,block,id;
    node(){}
    node(int a,int b,int c):l(a),r(b),id(c){
        block=l/block_size;
    }
    bool operator<(const node &a)const{
        return block==a.block?r<a.r:block<a.block;
    }
}q[10010];
int n,m,ans1=0;
inline void add(int x){
    if (!vis[x])
        ans1++;
    vis[x]++;
}
inline void del(int x){
    if (--vis[x]==0)
        ans1--;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        q[i]=node(x,y,i);
    }
    sort(q+1,q+1+m);
    int l=1,r=0;
    for (int i=1;i<=m;i++){
        node now=q[i];
        while(l<now.l) del(a[l++]);
        while(l>now.l) add(a[--l]);
        while(r<now.r) add(a[++r]);
        while(r>now.r) del(a[r--]);
        ans[now.id]=ans1;
    }
    for (int i=1;i<=m;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
