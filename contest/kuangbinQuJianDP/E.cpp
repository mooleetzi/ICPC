/*
    dp[i][j]:[i,j)区间的答案
    转移方程：dp[i][j]=min{dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]}
*/
// #include<bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e2 + 10;
int a[maxn];
int dp[maxn][maxn];
int n;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++)
        cin >> a[i], dp[i][i] = 0;
    for (int l = 1; l <= n; l++)
        for (int i = 2; i + l <= n; i++)
        {
            int j = i + l;
            for (int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j]);
        }
    cout << dp[2][n];
    return 0;
}
