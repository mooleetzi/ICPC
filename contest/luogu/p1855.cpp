#include<bits/stdc++.h>
using namespace std;
const int maxn = 220;
int n, m, t;
int dp[maxn][maxn];
int M[maxn], T[maxn];
int main(int argc, char const *argv[])
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n;i++)
        cin >> M[i] >> T[i];
    for (int i = 1; i <= n;i++){
        for (int j = m; j >=M[i];j--)
            for (int k =t; k >=T[i];k--)
                dp[j][k] = max(dp[j][k], dp[j - M[i]][k - T[i]] + 1);
    }
    cout<<dp[m][t];
    return 0;
}
