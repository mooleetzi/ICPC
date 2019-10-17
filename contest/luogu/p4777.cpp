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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
ll mul(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll ret = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return ret;
}
ll ex_crt(int n, ll *m, ll *r)
{
    ll M = m[1], ans = r[1]; //第一个方程
    for (int i = 2; i <= n; i++)
    {
        ll a = M, b = m[i], c = (r[i] - ans % b + b) % b; //ax≡c(mod b)
        ll x, y;
        ll gcd = exgcd(a, b, x, y);
        ll t = m[i] / gcd;
        if (c % gcd)
            return -1; //判断是否无解
        x = mul(x, c / gcd, t);
        // x *= c / gcd;
        // x = (x % t + t) % t;
        ans += x * M; //更新前k个方程组的答案
        M *= t;       //M为前k个m的lcm
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}
ll a[maxn], b[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 1; i <= n; i++)
        a[i] = read<ll>(), b[i] = read<ll>();
    writeln(ex_crt(n, a, b));
    return 0;
}