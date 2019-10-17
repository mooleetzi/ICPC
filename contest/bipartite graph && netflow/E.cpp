/*
    二分图染色+最大匹配
 */
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 2e2 + 10;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = (ret << 1) + (ret << 3) + ch - '0';
        ch = getchar();
    }
    ret *= f;
    return ret;
}
template <class T>
inline void write(T n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        write(n / 10);
    }
    putchar(n % 10 + '0');
}
int vis[maxn], g[maxn][maxn], llink[maxn];
int dfs(int u, int c)
{
    vis[u] = c;
    for (int i = 1; i <= n; i++)
    {
        if (g[u][i])
        {
            if (vis[i] == -1)
                dfs(i, c ^ 1);
            else if (vis[i] == c)
                return 0;
        }
    }
    return 1;
}
int find(int u)
{
    for (int i = 1; i <= n; i++)
    {
        if (g[u][i])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                if (llink[i] == -1 || find(llink[i]))
                {
                    llink[i] = u;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int maxMatch()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof vis);
        res += find(i);
    }
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m)
    {
        memset(g, 0, sizeof g);
        memset(llink, -1, sizeof llink);
        memset(vis, -1, sizeof vis);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x][y] = 1;
        }
        int f = 1;
        for (int i = 1; i <= n && f; i++)
            if (vis[i] == -1)
            {
                f = dfs(i, 0);
            }
        if (!f)
            cout << "No\n";
        else
        {
            cout << maxMatch() << "\n";
        }
    }
    return 0;
}
