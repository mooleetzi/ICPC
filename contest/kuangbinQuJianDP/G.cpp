#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 20;
int a[maxn], dp[maxn][maxn], pre[maxn];
int n;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        cin >> n;
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++)
            cin >> a[i], pre[i] = pre[i - 1] + a[i];
        for (int l = 1; l <= n; l++)
            for (int i = 1; i + l <= n; i++)
            {
                int j = i + l;
                dp[i][j] = 1e9;
                for (int k = i; k <= j; k++)
                    dp[i][j] = min(dp[i][j], dp[i + 1][k] + a[i] * (k - i) + dp[k + 1][j] + (pre[j] - pre[k]) * (k - i + 1));
            }
        cout << "Case #" << cas << ": " << dp[1][n] << "\n";
    }
    return 0;
}