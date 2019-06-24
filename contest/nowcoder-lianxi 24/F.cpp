#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
const int mod=19260817;
int f[maxn],v[maxn];
int main(){
    int n,m;
    ios::sync_with_stdio(false);
    cin>>n>>m;
    f[0]=1;
    for (int i=1;i<=n;i++){
        cin>>v[i];
        for (int j=v[i];j<=m;j++){
            f[j]+=f[j-v[i]];
            if (f[j]>=mod)
                f[j]-=mod;
        }
    }
    int ans=0;
    for (int i=1;i<=m;i++)
        ans+=f[i],ans>=mod?ans-=mod:ans;
    cout<<ans;
}
