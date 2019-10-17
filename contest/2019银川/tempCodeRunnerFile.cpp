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
const int maxn = 2e2 + 10;
int n, m, k;
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
int r[maxn];
vector<P> g[maxn];
ll dis[maxn];
ll dijk(int s, int t, int ww)
{
    for (int i = 1; i <= n; i++)
        dis[i] = 1e14;
    dis[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, s);
    while (!que.empty())
    {
        P tmp = que.top();
        que.pop();
        int u = tmp.second;
        if (dis[u] < tmp.first)
            continue;
        if (u == t)
            break;
        int sz = g[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = g[u][i].second;
            ll w = g[u][i].first;
            if (r[v] > ww && v != t)
                continue;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                que.emplace(dis[v], v);
            }
        }
    }
    return dis[t];
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    for (int cas = 1; cas <= t; cas++)
    {
        printf("Case #%d:\n", cas);
        n = read<int>(), m = read<int>();
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i <= n; i++)
            r[i] = read<int>();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                int x = read<int>();
                g[i].emplace_back(x, j);
            }
        while (m--)
        {
            int u = read<int>(), v = read<int>(), w = read<int>();
            write(dijk(u, v, w));
            puts("");
        }
    }
    return 0;
}
