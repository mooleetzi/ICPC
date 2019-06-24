/*
    区间dp
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e3 + 10;
int n,m;
char s[maxn];
int dp[maxn][maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s+1;
    for (int i = 1; i <= n;i++)
        dp[i][i] = 1;
    for (int len = 1; len <=n;len++){
        for (int i = 1; i + len <= n;i++){
            int j = i + len;
            if (s[i]==s[j])
                dp[i][j] = dp[i + 1][j - 1] + 1;
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
            for (int k = i; k <= j;k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] - 1);
        }
    }
    cout << dp[1][n];
    return 0;
}
