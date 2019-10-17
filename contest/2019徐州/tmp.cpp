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
int n, m;
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
const int maxn = 15;
ll q, C[maxn], M[maxn], x, y;
ll mp[100];
ll t;
inline bool judge(ll x)
{
    for (int i = 0; i < 71; i++)
        if (mp[i] == x)
            return 1;
    return 0;
}
ll mul(ll a, ll b, ll mod)
{
    ll res = 0;
    a %= mod;
    while (b)
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
    ll M = m[1], ans = r[1]; //第一个方程的解特判
    for (int i = 2; i <= n; i++)
    {
        ll a = M, b = m[i], c = (r[i] - ans % b + b) % b; //ax≡c(mod b)
        ll x, y;
        ll gcd = exgcd(a, b, x, y);
        ll t = m[i] / gcd;
        if (c % gcd)
            return -1; //判断是否无解，然而这题其实不用
        x = mul(x, c / gcd, t);
        // x *= c / gcd;
        // x = (x % t + t) % t;
        ans += x * M; //更新前k个方程组的答案
        M *= t;       //M为前k个m的lcm
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll a = 1, b = 1;
    while (a <= 1e18)
    {
        mp[t++] = a;
        ll tmp = b;
        b = a + b;
        a = tmp;
    }
    int q = read<int>();
    for (int i = 1; i <= q; i++)
        M[i] = read<ll>(), C[i] = read<ll>();
    bool flag = 1;
    ll ans = ex_crt(q, M, C);
    if (ans == -1)
    {
        printf("Tankernb!");
    }
    else
    {
        ll p = ans;
        if (judge(p))
            printf("Lbnb!");
        else
            printf("Zgxnb!");
    }
    return 0;
}