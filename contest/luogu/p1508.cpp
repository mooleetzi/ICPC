#include<bits/stdc++.h>
using namespace std;
const int maxn = 300;
int dp[maxn][maxn];
int a[maxn][maxn];
int n,m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> a[i][j];
    for (int i = 1; i <= n+1;i++)
        for (int j = 1; j <= m;j++){
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = max(dp[i - 1][j - 1], dp[i][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
            dp[i][j] += a[i][j];
        }
    cout << dp[n + 1][m / 2+1];
}