#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 10;
int dp[maxn],a[maxn][maxn];
int n,m;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin >> a[i][j];
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        dp[i] = 1;
        for (int k = 1; k < i;k++){
            int flag = 1;
            for (int j = 1; j <= m;j++)
                if (a[i][j]>=a[k][j]){
                    flag = 0;
                    break;
                }
            if (flag)
                dp[i] = max(dp[k] + 1, dp[i]);
        }
        cnt = max(cnt, dp[i]);
    }
    cout << n - cnt;
    return 0;
}
