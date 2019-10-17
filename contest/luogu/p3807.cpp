#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
int n, m, k, p;
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
inline ll qpow(ll a, int b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

inline ll fac(int x)
{
    ll res = 1;
    for (ll i = 2; i <= x; i++)
        res = (res * i % p) % p;
    return res;
}
inline ll inv(int x)
{
    ll res = fac(x);
    return qpow(res, p - 2);
}
inline ll C(ll n, ll m, ll p)
{
    if (m > n)
        return 0;
    return fac(n) * inv(m) % p * inv(n - m) % p;
}

inline LL lucas(LL n, LL m, LL p)
{
    ll res = 1;
    while (n | m)
    {
        res = res * C(n % p, m % p, p) % p;
        n /= p, m /= p;
    }
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
        n = read<ll>(), m = read<ll>(), p = read<ll>();
        write(lucas(n + m, m, p));
        puts("");
    }
    return 0;
}
