//找规律发现序列每个数出现次数为n^(k-1)
//快速幂即可
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k, mod;
const ll maxn = 1LL << 31;
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
int qpow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int a[1010];
ll solve()
{
    ll ans = 0;
    ll p = (qpow(n, k - 1) * (k % mod)) % mod;
    for (int i = 0; i < n; i++)
        ans = (ans + p * a[i] % mod) % mod;
    return ans;
}
int main(int argc, char const *argv[])
{
    int t;
    read(t);
    int tot = 0;
    while (t--)
    {
        read(n), read(k), read(mod);
        for (int i = 0; i < n; i++)
            read(a[i]);
        printf("Case %d: %lld\n", ++tot, solve());
    }
    return 0;
}
