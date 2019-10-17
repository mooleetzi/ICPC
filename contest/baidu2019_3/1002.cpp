/*
    dijk变形 求最短路径上的标号最大点的最小值之和
    对于单条最短路径求最大点即可
    对于多条最短路，求最小的最大点
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
#include <unordered_map>
#include <unordered_set>
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
int n, m, k;
const int maxn = 1e3 + 10;
ll a[maxn][maxn];
const ll inf = 0x3f3f3f3f * (ll)maxn;
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
ll dis[maxn];
int vis[maxn], d[maxn];
vector<P> g[maxn];
int dijk(int x)
{
    priority_queue<P, vector<P>, greater<P>> que;
    while (!que.empty())
        que.pop();
    for (int i = 1; i <= n; i++)
        dis[i] = inf, vis[i] = 0, d[i] = 0;
    que.emplace(0, x);
    dis[x] = 0;
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
            P cur = g[u][i];
            int v = cur.second;
            ll w = cur.first;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (u == x)
                    d[v] = 0;
                else
                    d[v] = max(d[u], u);
                que.emplace(dis[v], v);
            }
            else if (dis[v] == dis[u] + w)
            {
                int t = 0;
                if (u == x)
                    t = 0;
                else
                    t = max(d[u], u);
                if (d[v] > t)
                {
                    d[v] = t;
                    que.emplace(dis[v], v);
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += d[i];
    return res;
}
ll solve()
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += dijk(i);
    return res % 998244353;
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
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i == j)
                    a[i][j] = 0;
                else
                    a[i][j] = inf;
        for (int i = 1; i <= m; i++)
        {
            int x = read<int>();
            int y = read<int>();
            int z = read<int>();
            g[x].emplace_back(z, y);
            g[y].emplace_back(z, x);
        }
        write(solve());
        puts("");
    }
    return 0;
}
