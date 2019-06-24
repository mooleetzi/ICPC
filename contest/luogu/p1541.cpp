#include<bits/stdc++.h>
using namespace std;
const int maxn = 410;
int ans;
int a[maxn], b[maxn],g[5];
int n, k;
int dp[50][50][50][50];
int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= k;i++){
        int x;
        cin >> x;
        ++g[x];
    }
    // dp[0][0][0][0] = a[1];
    for (int i = 0; i <= g[1];i++)
        for (int j = 0; j <= g[2];j++)
            for (int k = 0; k <= g[3];k++)
                for (int q = 0; q <= g[4];q++){
                    if (i)
                        dp[i][j][k][q] = max(dp[i][j][k][q],dp[i - 1][j][k][q]);
                    if (j)
                        dp[i][j][k][q] = max(dp[i][j][k][q], dp[i][j - 1][k][q]);
                    if (k)
                        dp[i][j][k][q] = max(dp[i][j][k][q], dp[i][j][k-1][q]);
                    if (q)
                        dp[i][j][k][q] = max(dp[i][j][k][q], dp[i][j][k][q-1]);
                    dp[i][j][k][q] += a[1+i + 2 * j + 3 * k + 4 * q];
                    ans = max(ans, dp[i][j][k][q]);
                }
    cout << ans;
    return 0;
}
