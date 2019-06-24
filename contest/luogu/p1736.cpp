#include<bits/stdc++.h>
// #define DEBUG
using namespace std;
const int maxn = 25e2 + 5;
int n, m;
int a[maxn][maxn];
int dp[maxn][maxn];
int lx[maxn][maxn], ly[maxn][maxn];
void print(){
    cout<<"\n";
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
        for (int j = 1; j <= m;j++)
            cin >> a[i][j];
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            lx[i][j] = lx[i][j - 1] + a[i][j], ly[i][j] = ly[i - 1][j] + a[i][j];
    int ans1 = 0,ans2=0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m;j++){
            if (a[i][j]){
                for (int left = 1; left<=dp[i-1][j-1];left++)
                    if (lx[i][j - 1] - lx[i][j - left - 1] == 0 && ly[i - 1][j] - ly[i - 1 - left][j] == 0){
                        dp[i][j] = left;
                    }
                    else
                    {
                        break;
                    }

                ++dp[i][j];
                ans1 = max(ans1, dp[i][j]);
            }
        }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            dp[i][j] = 0;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            if (a[i][j]){
                for (int left = 1; left <= dp[i - 1][j + 1];left++)
                    if (lx[i][j+left]-lx[i][j]==0&&ly[i-1][j]-ly[i-left-1][j]==0)
                        dp[i][j] = left;
                    else
                    {
                        break;
                    }
                ++dp[i][j];
                ans2 = max(ans2, dp[i][j]);
            }
        }
#ifdef DEBUG
    print();
#endif
    cout << max(ans1, ans2);
    return 0;
}
