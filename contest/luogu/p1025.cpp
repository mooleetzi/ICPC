#include <bits/stdc++.h>
using namespace std;
const int maxn = 250;
int dp[maxn][maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 1; i <= n;i++)
        dp[i][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= i; j++)
            dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
    cout << dp[n][m];
}