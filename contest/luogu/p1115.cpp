#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
typedef long long ll;
ll ans=-0x3f3f3f3f;
ll dp[maxn];
ll a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++){
        dp[i]=max(dp[i-1]+a[i],a[i]);
        ans=max(dp[i],ans);
    }
    cout<<ans<<"\n";
    return 0;
}
