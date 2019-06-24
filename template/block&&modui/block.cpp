#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int block_size=200;
int c[maxn],a[maxn],block[maxn],v[maxn];
int main(){
    int n,m;
    scanf("%d",&n);
    memset(v,0,sizeof v);
    memset(block,0,sizeof block);
    memset(a,0,sizeof a);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]),block[i]=i/block_size+1;
    scanf("%d",&m);
    while(m--){
        int x,y,z,k;
        scanf("%d",&x);
        if (x==1){
            scanf("%d%d%d",&y,&z,&k);
            if (block[z]-block[y]<2){
                for (int i=y;i<=z;i++)
                    a[i]+=k;
            }
            else{
                for (int i=block[y]+1;i<block[z];i++)
                    v[i]+=k;
                for (int i=y;i<block[y]*block_size;i++)
                    a[i]+=k;
                for (int i=z;i>=block[z]*block_size;i--)
                    a[i]+=k;
            }
        }
        else if (x==2){
            scanf("%d",&y);
            printf("%d\n",v[block[y]]+a[y]);
        }
    }
    return 0;
}

