#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn];
int n, t;
int dp[maxn][2];
int main(int argc, char const *argv[])
{
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n;i++)
            cin >> a[i];
        memset(dp, 0, sizeof dp);
        dp[0][1] = a[0];
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            dp[i][1] = dp[i - 1][0] + a[i];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            ans = max(dp[i][1], ans);
            ans = max(dp[i][0], ans);
        }
        cout << ans << "\n";
    }
    return 0;
}