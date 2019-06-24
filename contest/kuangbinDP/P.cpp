#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int a[maxn][maxn], f[maxn][maxn];
int n, m;
int dp(int x, int y)
{
    if (f[x][y])
        return f[x][y];
    int now = a[x][y];
    for (int i = 1; i <= m; i++)
    {
        if (x + i <= n && a[x + i][y] > a[x][y])
            now = max(now, dp(x + i, y) + a[x][y]);
        if (x - i > 0 && a[x - i][y] > a[x][y])
            now = max(now, dp(x - i, y) + a[x][y]);
        if (y + i <= n && a[x][y + i] > a[x][y])
            now = max(now, dp(x, y + i) + a[x][y]);
        if (y - i > 0 && a[x][y - i] > a[x][y])
            now = max(now, dp(x, y - i) + a[x][y]);
    }
    return f[x][y] = now;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m && n != -1 && m != -1)
    {
        int maxx = 0, ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        memset(f, 0, sizeof f);
        cout << dp(1,1) << "\n";
    }
    return 0;
}