#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int dp[maxn][maxn];
int sum[maxn];
int n, a[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(dp, 0x3f, sizeof dp);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
            dp[i][i] = 0;
        }
        for (int len = 1; len <=n;len++)
            for (int i = 1; i + len <= n;i++){
                int j = i + len;
                for (int k = i; k <j;k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i - 1]);
            }
        cout << dp[1][n] << "\n";
    }
    return 0;
}
