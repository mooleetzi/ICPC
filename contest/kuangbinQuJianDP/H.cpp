#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
char s1[maxn], s2[maxn];
int dp[maxn][maxn],ans[maxn];
int n,m;
int main(int argc, char const *argv[])
{
    while(cin>>(s1+1)>>(s2+1)){
        n = strlen(s1 + 1);
        for (int i = 1; i <= n;i++)
            for (int j = i; j <= n;j++)
                dp[i][j] = j - i + 1;
        for (int i=n;i>=1;i--)
            for (int j=i;j<=n;j++){
                dp[i][j] = dp[i + 1][j] + 1;
                for (int k = i+1; k <= j;k++)
                    if (s2[k]==s2[i])
                        dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k+1][j]);
            }
        for (int i = 1; i <= n;i++)
            ans[i] = dp[1][i];
        for (int i = 1; i <= n;i++){
            if (s1[i]==s2[i])
                ans[i] = ans[i - 1];
            for (int j = 1; j < i;j++)
                ans[i] = min(ans[i], ans[j] + dp[j+1][i]);
        }
            cout << ans[n] << "\n";
    }
    return 0;
}
