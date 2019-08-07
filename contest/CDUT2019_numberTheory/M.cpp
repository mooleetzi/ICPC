/*
区间素数筛板题
注意a为1时需要减去1
 */
#pragma optimize(3)
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k, mod;
const int maxn = 1e5 + 10;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
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

ll multiMod(ll a, ll b, ll mod)
{
    ll ret = 0LL;
    a %= mod;
    while (b)
    {
        if (b & 1LL)
            ret = (ret + a) % mod, --b;
        b >>= 1LL;
        a = (a + a) % mod;
    }
    return ret;
}

bool isprime1[maxn], isprime2[maxn];
int solve(ll a, ll b)
{
    for (ll i = 0; i * i <= b; i++)
        isprime1[i] = 0;
    for (ll i = 0; i <= b - a; i++)
        isprime2[i] = 1;
    for (ll i = 2; i * i <= b; i++)
    {
        if (!isprime1[i])
        {
            for (ll j = i + i; j * j <= b; j += i)
                isprime1[j] = 1;
            for (ll j = max(2LL, (a + i - 1) / i) * i; j <= b; j += i)
                isprime2[j - a] = 0;
        }
    }
    int sum = 0;
    for (int i = 0; i <= b - a; i++)
        if (isprime2[i])
            sum++;
    if (a == 1)
        --sum;
    return sum;
}
int main(int argc, char const *argv[])
{
    int t;
    read(t);
    int tot = 0;
    while (t--)
    {
        int a, b;
        read(a), read(b);
        printf("Case %d: %d\n", ++tot, solve(a, b));
    }
    return 0;
}
