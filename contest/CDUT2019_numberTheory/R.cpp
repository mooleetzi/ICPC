// #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
// using ll = long long;
// using ull = unsigned long long;
// using pa = pair<int, int>;
// using ld = long double;
typedef long long ll;
const int maxn = 5100;
const int mod = 100000007;
ll n, k, m, pre, r;
// template <class T>
// inline T read(T &ret)
// {
//     int f = 1;
//     ret = 0;
//     char ch = getchar();
//     while (!isdigit(ch))
//     {
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }
//     while (isdigit(ch))
//     {
//         ret = (ret << 1) + (ret << 3) + ch - '0';
//         ch = getchar();
//     }
//     ret *= f;
//     return ret;
// }
// template <class T>
// inline void write(T n)
// {
//     if (n < 0)
//     {
//         putchar('-');
//         n = -n;
//     }
//     if (n >= 10)
//     {
//         write(n / 10);
//     }
//     putchar(n % 10 + '0');
// }
void swap(ll &a, ll &b)
{
    ll t = a;
    a = b;
    b = t;
}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
int main(int argc, char const *argv[])
{
    ll x, y, m, n, l;
    // read(x), read(y), read(m), read(n), read(l);
    scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l);
    char im[] = "Impossible";
    if (m == n)
    {
        puts(im);
    }
    else
    {
        ll a = n - m, b = x - y;
        ll xa, yl;
        ll d = exgcd(a, l, xa, yl);
        if (b % d != 0)
        {
            puts(im);
        }
        else
        {
            ll times = l / d;
            xa *= (x - y) / d;                 //最终解
            xa = (xa % times + times) % times; //最小非负整数解
            printf("%lld\n", xa);
        }
    }
    return 0;
}
