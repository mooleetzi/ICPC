#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 10;
int dp[maxn];
int main()
{
    int n, m,t;
    cin >> t >> m;
    for (int i = 0;i<m;i++){
        int tim, v;
        cin >> tim >> v;
        for (int j = tim; j <= t;j++)
            dp[j] = max(dp[j], dp[j - tim] + v);
    }
    int ans = 0;
    for (int i = 0; i <= t; i++)
        ans = max(ans, dp[i]);
    cout << ans << "\n";
}