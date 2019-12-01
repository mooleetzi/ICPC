#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define pblank putchar(' ')
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 1e5 + 10;
template <class T>
inline T read()
{
    int f = 1;
    T ret = 0;
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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
vector<int> dep[202];
vector<int> g[202];
int v[202], d[202], maxd;
void dfs(int u, int p)
{
    d[u] = d[p] + 1;
    maxd = max(maxd, d[u]);
    dep[d[u]].emplace_back(u);
    int sz = g[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = g[u][i];
        if (v == p)
            continue;
        dfs(v, u);
    }
}
void dfs2(int u, int step, int x)
{
    v[u] -= x;
    if (step == k)
        return;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = g[u][i];
        if (d[v] > d[u])
            continue;
        dfs2(v, step + 1, x);
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), k = read<int>();
    for (int i = 1; i <= n; i++)
        v[i] = read<int>();
    for (int i = 0; i < n - 1; i++)
    {
        int x = read<int>(), y = read<int>();
        g[x].emplace_back(y), g[y].emplace_back(x);
    }
    dfs(1, 0);
    int res = 0;
    // for (int i = 1; i <= maxd; i++)
    // {
    //     write(i), pblank;
    //     int sz = dep[i].size();
    //     for (int j = 0; j < sz; j++)
    //         write(dep[i][j]), pblank;
    //     puts("");
    // }
    for (int i = maxd; i >= 1; i--)
    {
        for (int u : dep[i])
        {
            if (v[u] > 0)
            {
                int cur = v[u];
                res += cur;
                dfs2(u, 0, cur);
            }
        }
    }
    writeln(res);
    return 0;
}