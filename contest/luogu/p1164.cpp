#include<iostream>
#include<algorithm>
using namespace std;
int dp[1010];
int a[110];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[0]=1;
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        for (int j=m;j>=a[i];j--)
            dp[j]+=dp[j-a[i]];
    cout<<dp[m]<<"\n";
    return 0;
}
