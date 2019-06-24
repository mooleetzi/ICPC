#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int a[maxn][maxn];
int ans[maxn];
int n, m,flag;
double s;
int dp[maxn][maxn];
// void dfs(int row, int col, int now)
// {
//     if (flag||(clock()-s)/CLOCKS_PER_SEC>.99)
//         return;
//     if (row==n+1){
//         if (now){
//             puts("TAK");
//             for (int i = 1; i <= n; i++)
//                 cout << ans[i] << " ";
//             flag = 1;
//         }
//         return;
//     }
//     ans[row] = col;
//     for (int i = 1; i <= m; i++)
//     {
//         if (a[row+1][i]^now)
//             dfs(row + 1, i,a[row+1][i] ^ now);
//     }
// }
inline int read(){
    register int f = 1, ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
        /* code */
    }
    return ans * f;
}
int main(int argc, char const *argv[])
{
    // ios::sync_with_stdio(false);
    s = clock();
    // cin >> n >> m;
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m;j++)
            a[i][j] = read();
    for (int i = 1; i <= n;i++)
        for (int j = 1;j<=m;j++){
            for (int k = 1;k<=m;k++)
                if (dp[i-1][k]^a[i][j]){
                    ans[i] = j;
                    dp[i][j] = dp[i - 1][k] ^ a[i][j];
                }
        }
    for (int i = 1;i<=m;i++)
        if (dp[n][i])
        {
            cout << "TAK\n";
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            return 0;
        }
    puts("NIE");
    return 0;
}
