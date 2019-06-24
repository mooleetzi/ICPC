#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;
ll dp[maxn];
int a[maxn];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int l = 2;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
        dp[i] = max(dp[i - 1] + a[i], (ll)a[i]);
    ll ans = -maxn;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}