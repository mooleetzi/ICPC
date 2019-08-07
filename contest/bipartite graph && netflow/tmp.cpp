#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 1e3 + 10;
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
int row[maxn], vis[maxn];
vector<int> g1[maxn], g2[maxn];
inline void init()
{
    memset(row, -1, sizeof(int) * (n + 2));
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++)
        g1[i].clear(), g2[i].clear();
}
inline void add(int x, int y)
{
    g1[x].emplace_back(y);
    g2[y].emplace_back(x);
}
int find(int u)
{
    int sz = g1[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = g1[u][i];
        if (!vis[v])
        {
            vis[v] = 1;
            if (row[v] == -1 || find(row[v]))
            {
                row[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int maxMacth()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(int) * (m + 1));
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
    while (cin >> n >> m >> k && (m + n + k))
    {
        init();
        for (int i = 0; i < k; i++)
        {
            int x, y;
            // read(x), read(y);
            cin >> x >> y;
            add(x, y);
        }
        int ans = maxMacth();
        cout << ans << " ";
        vector<pair<char, int>> out;
        out.clear();
        for (int i = 1; i <= m; i++)
            if (row[i] != -1)
            {
                if (g1[row[i]].size() > g2[i].size())
                {
                    out.emplace_back('r', row[i]);
                }
                else
                {
                    out.emplace_back('c', i);
                }
            }
        sort(out.begin(), out.end());
        for (int i = 0; i < ans - 1; i++)
            cout << out[i].first << out[i].second << " ";
        cout << out[ans - 1].first << out[ans - 1].second << '\n';
    }
    return 0;
}