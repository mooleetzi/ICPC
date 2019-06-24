//查询区间小于x的值
//更新区间值
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+20;
int block_size;
int a[maxn],b[maxn],block[maxn],v[maxn];
int n,m;
void reset(int x){
    if (x==block[n])
        return;
    for (int i=(x-1)*block_size+1;i<block_size*x;i++)
        b[i]=a[i];
    sort(b+1+block_size*(x-1),b+1+block_size*x);
}
int main(){
    cin>>n>>m;
    block_size=sqrt(n);
    for (int i=1;i<=n;i++){
        cin>>a[i],block[i]=i/block_size+1;
        if (block[i]>block[i-1])
            reset(block[i-1]);
    }
    while(m--){
        string s;
        int x,y,z;
        cin>>s>>x>>y>>z;
        if (s[0]=='Q'){
            int ans=0;
            if (block[y]-block[x]<2){
                for (int i=x;i<=y;i++)
                    if (a[i]+v[block[i]]<z)
                        ans++;
                printf("%d\n",ans);
            }
            else{
                for (int i=x;i<block_size*block[x];i++)
                    if (a[i]+v[block[i]]<z)
                        ans++;
                for (int i=block[x]+1;i<block[y];i++){
                    ans+=lower_bound(b+(block[i]-1)*block_size+1,b+block_size*block[i],z)-(b+(block[i]-1)*block_size+1);
                }
                for (int i=block[y]*block_size-block_size;i<=y;i++)
                    if (a[i]+v[block[i]]<z)
                        ans++;
                printf("%d\n",ans);
            }
        }
        else if (s[0]=='C'){
            if (block[y]-block[x]<2){
                for (int i=x;i<=y;i++)
                    a[i]+=z;
            }
            else{
                for(int i=x;i<block_size*block[x];i++)
                    a[i]+=z;
                reset(block[x]);
                for (int i=block[x]+1;i<block[y];i++)
                    v[i]+=z;
                for (int i=block[y]*block_size-block_size;i<=y;i++)
                    a[i]+=z;
                reset(block[y]);
            }
        }
    }
    return 0;
}
