#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn], dp[maxn][maxn], pre[maxn];
int n;
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
        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= n; i++)
            cin >> a[i], dp[i][i] = a[i] * (n - 1);
        for (int len = 1; len <= n; len++)
            for (int i = 1; i + len <= n; i++)
            {
                int j = i + len;
                dp[i][j] = 0x3f3f3f3f;
                for (int k = i; k <= j;k++){
                    if (k==1||k==n)
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
                    else
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]+a[k]*2);
                }
            }
        cout << dp[1][n] << "\n";
    }
    return 0;
}
