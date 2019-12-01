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
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
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
template <typename T>
void _write(const T &t)
{
    write(t);
}
template <typename T, typename... Args>
void _write(const T &t, Args... args)
{
    write(t), pblank;
    _write(args...);
}
template <typename T, typename... Args>
inline void write_line(const T &t, const Args &... data)
{
    _write(t, data...);
    puts("");
}
ll dis(const P &t1, const P &t2)
{
    return 1LL*abs(t1.first - t2.first) + abs(t1.second - t2.second);
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    n = read<int>();
    vector<P> vec(n + 1), con;
    vector<int> c(n + 1), k(n + 1), fa(n + 1, -1), vis(n + 1, 0), self;
    for (int i = 1; i <= n; i++)
    {
        int x = read<int>(), y = read<int>();
        vec[i] = P(x, y);
    }
    for (int i = 1; i <= n; i++)
        c[i] = read<int>();
    for (int i = 1; i <= n; i++)
        k[i] = read<int>();
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = -1, minx = 2e9;
        for (int j = 1; j <= n; j++)
            if (c[j] < minx && !vis[j])
            {
                minx = c[j];
                u = j;
            }
        if (u != -1)
            vis[u] = 1, res += minx;
        else
            break;
        if (fa[u] != -1)
            con.emplace_back(fa[u], u);
        else
            self.emplace_back(u);
        for (int j = 1; j <= n; j++)
        {
            if (j == u || vis[j])
                continue;
            ll d = 1LL * dis(vec[u], vec[j]) * (k[u] + k[j]);
            if (d < c[j])
                c[j] = d, fa[j] = u;
        }
    }
    writeln(res);
    int sz = self.size();
    writeln(sz);
    for (int i = 0; i < sz; i++)
        write(self[i]), pblank;
    puts("");
    sz = con.size();
    writeln(sz);
    for (int i = 0; i < sz; i++)
        write_line(con[i].first, con[i].second);
    return 0;
}