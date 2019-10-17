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
int n, m, k, c, d, e;
const int maxn = 1e5 + 10;
vector<P> g[maxn];
ll dis[maxn], cnt[maxn];
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

bool dijk(ll k)
{
    priority_queue<P, vector<P>, greater<P>> que;
    while (!que.empty())
        que.pop();
    for (int i = 1; i <= n; i++)
        dis[i] = 1e14, cnt[i] = 1e14;
    dis[1] = 0;
    cnt[1] = 0;
    que.emplace(0, 1);
    while (!que.empty())
    {
        P tmp = que.top();
        que.pop();
        int u = tmp.second;
        if (dis[u] > tmp.first)
            continue;
        int sz = g[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = g[u][i].second;
            ll w = g[u][i].first;
            if (w <= k * d)
            {
                if (dis[v] > dis[u] + w)
                {
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u] + 1;
                    que.emplace(dis[v], v);
                }
                else if (dis[v] == dis[u] + w)
                {
                    cnt[v] = min(cnt[v], cnt[u] + 1);
                }
            }
        }
    }
    return dis[n] < 1e14 && cnt[n] <= (ll)k * e;
}
ll solve()
{
    int l = 1, r = 1e5 + 1;
    ll res = -1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (dijk(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if (res == -1)
        return res;
    return res * c;
}
void init()
{
    for (int i = 2; i <= 100; i++)
    {
        map<int, int> mp;
        for (int j = 1; j <= i; j++)
            mp[__gcd(i, j)]++;
        cout << i << ": ";
        for (auto x : mp)
            cout << "(" << x.first << "," << x.second << ") ";
        cout << "\n";
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    return 0;
}
