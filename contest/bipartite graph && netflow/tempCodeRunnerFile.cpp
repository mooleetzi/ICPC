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
    while (read(n) && read(m) && read(k))
    {
        init();
        for (int i = 0; i < k; i++)
        {
            int x, y;
            read(x), read(y);
            add(x, y);
        }
        int ans = maxMacth();
        write(ans);
        putchar(' ');
        for (int i = 1; i <= m; i++)
            if (row[i] != -1)
            {
                if (g1[row[i]].size() > g2[i].size())
                {
                    putchar('r');
                    write(row[i]);
                    putchar(' ');
                }
                else
                {
                    putchar('c');
                    write(i);
                    putchar(' ');
                }
            }
        puts("");
    }
    return 0;
}
