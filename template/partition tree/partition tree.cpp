#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int depth=20;
inline int mid(int l,int r){
    return l+((r-l)>>1);
}
struct node{
    int num[maxn];
    int cnt[maxn];//进入左区间的数
    int l,r;
}tree[depth];
int sorted[maxn];
void build(int dep,int l,int r){
    if (l==r)
        return;
    int m=(l+r)>>1;
    int scnt=m-l+1;
    //开始计算进入左区间数
    for (int i=l;i<=r;i++)
        if (tree[dep].num[i]<sorted[m])
            scnt--;
    int lpos=l,rpos=m+1;
    for (int i=l,toleft=0;i<=r;i++){
        if (tree[dep].num[i]<sorted[m]||(tree[dep].num[i]==sorted[m]&&scnt)){
            if (tree[dep].num[i]==sorted[m]&&scnt)
                scnt--;
            tree[dep+1].num[lpos++]=tree[dep].num[i];
            toleft++;
        }
        else
            tree[dep+1].num[rpos++]=tree[dep].num[i];
        tree[dep].cnt[i]=toleft;
    }
    build(dep+1,l,m);
    build(dep+1,m+1,r);
}
int query(int L,int R,int l,int r,int dep,int k){
    if (l==r)
        return tree[dep].num[l];
    int m=(L+R)>>1;
    int cnt=tree[dep].cnt[r]-tree[dep].cnt[l-1];
    if (cnt>=k){
        int newl=L+tree[dep].cnt[l-1]-tree[dep].cnt[L-1];
        int newr=newl+cnt-1;
        return query(L,m,newl,newr,dep+1,k);
    }
    else{
        int newr=r+tree[dep].cnt[R]-tree[dep].cnt[r];
        int newl=newr-(r-l-cnt);
        return query(m+1,R,newl,newr,dep+1,k-cnt);
    }
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        for (int i=1;i<=n;i++)
            scanf("%d",&tree[0].num[i]),sorted[i]=tree[0].num[i];
        sort(sorted+1,sorted+1+n);
        build(0,1,n);
        for (int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            printf("%d\n",query(1,n,x,y,0,z));
        }
    }
    return 0;
}
