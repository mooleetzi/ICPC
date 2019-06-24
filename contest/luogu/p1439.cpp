#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int a[maxn],b[maxn],c[maxn];
int dp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i],c[a[i]]=i;
    for (int i=1;i<=n;i++)
        cin>>b[i];
    for (int i=1;i<=n;i++)
        dp[i]=maxn;
    int cnt=1;
    dp[1]=a[1];
    for (int i=2;i<=n;i++){
        if (c[b[i]]>dp[cnt])
            dp[++cnt]=c[b[i]];
        else{
            int ind=upper_bound(dp+1,dp+cnt+1,c[b[i]])-dp;
            dp[ind]=min(dp[ind],c[b[i]]);
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
