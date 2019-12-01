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
}
int a[maxn];
inline int isprime(int x)
{
    if (x == 2)
        return 1;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
ll dp1[maxn], dp2[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    ll s = 0;
    ll res = 0, pre = -1;
    for (int i = 1; i <= n; i++)
        a[i] = read<int>(), s += a[i];
    if (s == 1)
        puts("-1");
    else
    {
        int minx = -1;
        if (isprime(s))
            minx = s;
        else
            minx = 2;
        if (minx == 2)
        {
            for (int i = 1; i <= n; i++)
                if (a[i])
                {
                    if (pre == -1)
                        pre = i;
                    else
                        res += i - pre, pre = -1;
                }
            writeln(res);
        }
        else
        {
            res = 1e12;
            vector<ll> vec;
            vec.clear();
            for (int i = 1; i <= n; i++)
                if (a[i])
                    vec.emplace_back(i);
            for (ll i = 1; i < s; i++)
                dp1[i] += dp1[i - 1] + i * (vec[i] - vec[i - 1]);
            for (ll i = s - 2; i >= 0; i--)
                dp2[i] += dp2[i + 1] + (s - i - 1) * (vec[i + 1] - vec[i]);
            for (ll i = 0; i < s; i++)
                res = min(dp1[i] + dp2[i], res);
            writeln(res);
        }
    }
    return 0;
}