#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+10;
int inq[1000000+10];
int block_size,ans;
int a[maxn];
struct node{
    int l,r,id,block;
    node(){}
    node(int a,int b,int c):l(a),r(b),id(c){
        block=l/block_size;
    }
    bool operator<(const node &a)const{
        return block==a.block?r<a.r:block<a.block;
    }
}q[200010];
int b[200010];
inline void add(int x){
    if (inq[x])
        inq[x]++;
    else
        inq[x]=1,ans++;
}
inline void del(int x){
    if (--inq[x]==0)
        ans--;
}
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n;
    block_size=(int)sqrt(n);
    for (int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        q[i]=node(x,y,i);
    }
    sort(q+1,q+m+1);
    int l=1,r=0;
    for (int i=1;i<=m;i++){
        node now=q[i];
        if (now.l==now.r){
            b[now.id]=1;
            continue;
        }
        while(l<now.l) del(a[l++]);
        while(r<now.r) add(a[++r]);
        while(l>now.l) add(a[--l]);
        while(r>now.r) del(a[r--]);
        b[q[i].id]=ans;
    }
    for (int i=1;i<=m;i++)
        cout<<b[i]<<"\n";
}
