#include<bits/stdc++.h>
using namespace std;
const int block_size=200;
const int maxn=1e5+10;
int a[maxn],b[maxn],v[maxn/block_size],block[maxn/block_size],n,m;
void reset(int x){
    if (x==block[n])
        return;
    for (int i=block_size*(x-1)+1;i<=x*block_size;i++)
        b[i]=a[i];
    sort(b+block_size*(x-1)+1,b+block_size*x+1);
}
void add(int l,int r,int k){
    if (block[r]-block[l]<2){//不存在完整块
        for (int i=l;i<=r;i++)
            a[i]+=k;
        reset(block[l]);
        reset(block[r]);
    }
    else{
        for (int i=block[l]+1;i<block[r];i++)
            v[i]+=k;
        for (int i=l;i<=block[l]*block_size;i++)
            a[i]+=k;
        reset(block[l]);
        for (int i=r;i>=(block[r]-1)*block_size;i--)
            a[i]+=k;
        reset(block[r]);
    }
}
int query(int l,int r){
    if (block[r]-block[l]<2){
        int ans=0;
        for (int i=l;i<=r;i++)
            ans+=a[i];
    }
}
