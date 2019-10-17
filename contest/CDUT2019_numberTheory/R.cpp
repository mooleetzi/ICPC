#include <cstdio>
#include <iostream>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
typedef long long ll;
const int maxn = 5100;
const int mod = 100000007;
ll n, k, m, pre, r;
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
