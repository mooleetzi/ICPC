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
typedef pair<ll, ll> P;
ll n, m, k;
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
vector<P> cood;
unordered_map<ll, ll> mx, my;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("test.txt", "w", stdout);
#endif
    int t = read<int>();
    for (int cas = 1; cas <= t; cas++)
    {
        n = read<ll>();
        mx.clear(), my.clear();
        cood.clear();
        for (int i = 0; i < n; i++)
        {
            int x = read<ll>(), y = read<ll>();
            cood.emplace_back(x, y);
            mx[x]++;
            my[y]++;
        }
        ll maxx = 0, maxy = 0;
        for (int i = 0; i < n; i++)
        {
            if (mx[cood[i].first] > maxx)
                maxx = mx[cood[i].first];
            if (my[cood[i].second] > maxy)
                maxy = my[cood[i].second];
        }
        if (mx.size() == 1 || my.size() == 1)
        {
            printf("Case %d: %d 1\n", cas, n);
            continue;
        }
        if (maxx == 1 && maxy == 1)
        {
            printf("Case %d: 2 %lld\n", cas, 1LL * n * (n - 1) / 2);
            continue;
        }
        ll cntx_1, cntx_2, cnty_1, cnty_2;
        cntx_1 = cntx_2 = cnty_1 = cnty_2 = 0;
        for (auto it : mx)
            if (it.second == maxx)
                ++cntx_1;
            else if (it.second == maxx - 1)
                ++cntx_2;
        for (auto it : my)
            if (it.second == maxy)
                ++cnty_1;
            else if (it.second == maxy - 1)
                ++cnty_2;
        ll res = maxx + maxy, cs1 = cntx_1 * cnty_1, cs2 = cntx_1 * cnty_2 + cntx_2 * cnty_1;
        for (auto it : cood)
        {
            ll cur = mx[it.first] + my[it.second];
            if (cur == res)
                cs1--, cs2++;
            else if (cur == res - 1)
                cs2--;
        }
        if (cs1)
            printf("Case %d: %lld %lld\n", cas, res, cs1);
        else
            printf("Case %d: %lld %lld\n", cas, res - 1, cs2);
    }
    return 0;
}