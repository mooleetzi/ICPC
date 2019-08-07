//二分图染色
//图可能不联通，对于每一个联通块取最小的染色数目
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 1e4 + 10;
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
vector<int> g[maxn];
int col[maxn];
int t[2];
int f = 1;
int ans = 0;
void dfs(int u, int c)
{
    if (!f)
        return;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (col[v] == -1)
        {
            col[v] = c ^ 1;
            ++t[c ^ 1];
            dfs(v, c ^ 1);
        }
        else if (col[v] == c)
        {
            f = 0;
            return;
        }
    }
}
int main(int argc, char const *argv[])
{
    memset(col, -1, sizeof col);
    read(n);
    read(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        read(x), read(y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    for (int i = 1; i <= n && f; i++)
        if (col[i] == -1)
        {
            col[i] = 0;
            t[0] = 1;
            t[1] = 0;
            dfs(i, 0);
            ans += min(t[0], t[1]);
        }
    if (!f)
        puts("Impossible");
    else
        write(ans);
    return 0;
}
