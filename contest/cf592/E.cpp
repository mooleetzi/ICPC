#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
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
unordered_map<ll, int> mp;
vector<ll> a, b;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    ll q = read<ll>();
    for (int i = 1; i <= n; i++)
    {
        ll x = read<ll>();
        ++mp[x];
        a.emplace_back(x);
        b.emplace_back(-x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto aend = unique(a.begin(), a.end());
    auto bend = unique(b.begin(), b.end());
    ll minx = a.front(), maxx = a.back();
    while (q)
    {
        if (minx == maxx)
            break;
        int lminx = mp[minx];
        int lmaxx = mp[maxx];
        if (lminx < lmaxx)
        {
            auto pos = upper_bound(a.begin(), aend, minx);
            ll dec = *pos - minx;
            if (dec * lminx <= q)
            {
                q -= dec * lminx;
                mp[*pos] += lminx;
                mp.erase(minx);
                minx = *pos;
            }
            else
            {
                ll times = q / lminx;
                mp.erase(minx);
                minx += times;
                q = 0;
            }
        }
        else
        {
            auto pos = upper_bound(b.begin(), bend, -maxx);
            ll dec = maxx + *pos;
            if (dec * lmaxx <= q)
            {
                q -= dec * lmaxx;
                mp[-*pos] += lmaxx;
                mp.erase(maxx);
                maxx = -*pos;
            }
            else
            {
                ll times = q / lmaxx;
                mp.erase(maxx);
                maxx -= times;
                q = 0;
            }
        }
    }
    writeln(maxx - minx);
    return 0;
}