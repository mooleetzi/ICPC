#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int dp[maxn][maxn];
int a[maxn];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int cas = 1; cas <= t;cas++){
        cin >> n;
        for (int i = 1; i <= n;i++)
            cin >> a[i];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n;i++)
            for (int j = i; j <= n;j++)
                dp[i][j] = j - i + 1;
        for (int i = n; i >= 1;i--)
            for (int j = i + 1; j <= n;j++){
                dp[i][j] = dp[i + 1][j] + 1;
                for (int k = i + 1; k <=j;k++)
                    if (a[i]==a[k])
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
            }
        cout <<"Case "<<cas<<": " <<dp[1][n] << "\n";
    }
        return 0;
}