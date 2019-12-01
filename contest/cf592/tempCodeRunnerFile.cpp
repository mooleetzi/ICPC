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
set<ll> s;
unordered_map<ll, int> mp;
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
        s.emplace(x);
        ++mp[x];
    }
    for (; q;)
    {
        ll minx = *s.begin();
        ll maxx = *(--s.end());
        if (minx == maxx)
            break;
        int lminx = mp[minx];
        int lmaxx = mp[maxx];
        if (minx == maxx - 1)
        {
            int cur = min(lminx, lmaxx);
            if (q >= cur)
            {
                q = 0;
                s.clear();
                s.emplace(1);
            }
            else
            {
                q = 0;
                s.clear();
                s.emplace(1), s.emplace(2);
            }
        }
        else
        {
            if (q >= lminx + lmaxx)
            {
                q -= lminx + lmaxx;
                mp.erase(minx), mp.erase(maxx);
                mp[minx + 1] += lminx, mp[maxx - 1] += lmaxx;
                s.erase(minx), s.emplace(minx + 1), s.erase(maxx), s.emplace(maxx - 1);
            }
            else
            {
                int cur = min(lminx, lmaxx);
                if (q >= cur)
                {
                    s.clear();
                    s.emplace(minx);
                    s.emplace(maxx - 1);
                }
                break;
            }
        }
    }
    writeln(*(--s.end()) - *(s.begin()));
    return 0;
}