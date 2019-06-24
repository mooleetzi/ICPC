#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=5e5+10;
int f[maxn],vis[maxn],sum=0;
int main(){
    ios::sync_with_stdio(false);
    int n;
    memset(f,-1,sizeof f);
    cin>>n;
    int block=(int)sqrt(n+1);
    for (int i=0;i<n;i++)
        for (int j=i-block/2;j<=i+block/2;j++)
        if (j>-1&&j<n&&!vis[j]&&(i&j)==0){
            vis[j]=1;
            f[i]=j;
        }
    for (int i=0;i<n;i++)
        cout<<f[i]<<" ";
    return 0;
}

