#include<bits/stdc++.h>
// #define DEBUG
using namespace std;
const int maxn = 110;
int a[maxn][maxn];
int dp[maxn][maxn], n,m;
void print(){
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
            if (a[i][j])
                dp[i][j] = 1;
        }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m;j++){
            if (a[i][j]){
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] = min(dp[i][j - 1], dp[i][j]);
                ++dp[i][j];
                ans = max(ans, dp[i][j]);
            }
        }
        #ifdef DEBUG
            print();
        #endif
            cout << ans;
            return 0;
}
