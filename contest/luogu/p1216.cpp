#include<bits/stdc++.h>
using namespace std;
const int maxn = 1100;
int a[maxn][maxn];
int dp[maxn][maxn];
int n;
int main(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= i;j++)
            cin >>a[i][j];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= i;j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
    int ans = 0;
    for (int i = 1; i <= n;i++)
        ans = max(dp[n][i],ans);
    cout << ans;
    return 0;
}