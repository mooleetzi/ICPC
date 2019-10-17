/*
    递归欧拉降幂
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
unordered_map<ll, ll> mp;
ll Mod(ll a, ll b)
{
    return a < b ? a : a % b + b;
}
ll euler(ll x)
{
    if (mp.count(x))
        return mp[x];
    ll res = x, n = x;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        res = res / n * (n - 1);
    return mp[x] = res;
}
ll qpow(ll a, ll b, ll m)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = Mod(res * a, m);
        a = Mod(a * a, m);
        b >>= 1;
    }
    return res;
}
ll solve(ll a, ll b, ll m)
{
    if (b == 0)
        return Mod(1, m);
    if (m == 1)
        return Mod(a, m);
    int phi = euler(m);
    return qpow(a, solve(a, b - 1, phi), m);
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
        int a = read<int>(), b = read<int>();
        m = read<int>();
        write(solve(a, b, m) % m);
        puts("");
    }
    return 0;
}
