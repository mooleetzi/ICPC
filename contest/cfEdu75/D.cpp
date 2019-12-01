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
typedef pair<ll, ll> P;
int n, m, k;
const int maxn = 2e5 + 10;
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
vector<P> seg;
ll s;
int dep;
int vis[maxn];
inline int check(ll cur)
{
    int l = 0, r = 0, mid = 0;
    ll sum = 0;
    memset(vis, 0, sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++)
    {
        if (seg[i].first <= cur && seg[i].second >= cur)
            ++mid;
        else if (seg[i].second < cur)
        {
            vis[i] = 1;
            ++l;
            sum += seg[i].first;
        }
        else if (seg[i].first > cur)
        {
            ++r;
            vis[i] = 1;
            sum += seg[i].first;
        }
    }
    if (l > dep || r > dep)
        return 0;
    for (int i = 0; i < n; i++)
        if (l < dep && !vis[i])
            ++l, sum += seg[i].first;
        else if (r < dep && !vis[i])
            ++r, sum += cur;
    sum += cur;
    return sum <= s;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        seg.clear();
        n = read<int>();
        s = read<ll>();
        dep = n >> 1;
        for (int i = 1; i <= n; i++)
        {
            ll x = read<ll>(), y = read<ll>();
            seg.emplace_back(x, y);
        }
        sort(seg.begin(), seg.end());
        ll l = seg[dep].first, r = s;
        ll res = -1;
        while (l <= r)
        {
            ll mid = l + r >> 1;
            if (check(mid))
            {
                l = mid + 1;
                res = mid;
            }
            else
                r = mid - 1;
        }
        writeln(res);
    }
    return 0;
}