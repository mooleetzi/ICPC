/*
    两边dijk
    注意超级源点需要在跑超人之后加，否则会超人最短路会变短，答案不正确
*/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
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
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, int> P;
int n, m, k, s, c;
const int maxn = 1e5 + 10;
const ll inf = 1e14;
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
vector<P> g[maxn];
ll dis[maxn];
int a[maxn];
void add(int x, int y, ll z)
{
    g[x].emplace_back(z, y);
    g[y].emplace_back(z, x);
}
ll dijk(int s)
{
    priority_queue<P, vector<P>, greater<P>> que;
    while (!que.empty())
        que.pop();
    for (int i = 0; i <= n; i++)
        dis[i] = inf;
    dis[s] = 0;
    que.emplace(0, s);
    while (!que.empty())
    {
        P tmp = que.top();
        que.pop();
        int u = tmp.second;
        if (dis[u] < tmp.first)
            continue;
        int sz = g[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = g[u][i].second;
            int w = g[u][i].first;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                que.emplace(dis[v], v);
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dis[i]);
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        n = read<int>(), m = read<int>();
        s = read<int>();
        k = read<int>(), c = read<int>();
        for (int i = 0; i <= n; i++)
            g[i].clear();
        for (int i = 1; i <= k; i++)
            a[i] = read<int>();
        while (m--)
        {
            int x = read<int>(), y = read<int>(), z = read<ll>();
            add(x, y, z);
            add(y, x, z);
        }

        ll d1 = dijk(s);
        for (int i = 1; i <= k; i++)
            add(0, a[i], 0);
        ll d2 = dijk(0);
        if (d1 <= d2 * c)
            writeln(d1);
        else
            writeln(d2);
    }
    return 0;
}