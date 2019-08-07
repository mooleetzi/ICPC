#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const int maxn = 1e6 + 10;
const int mod = 998244353;
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
ll qpow(ll base, int n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int t;
    read(t);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (t--)
    {
        ll a, b, c, d;
        // read(a), read(b), read(c), read(d);
        cin >> a >> b >> c >> d;
        ll p0 = qpow(2, a + c);
        ll p1 = (b + d) * qpow(2, a + c) % mod;
        ll q0 = qpow(2, a + b);
        ll p0q0 = qpow(2, a);
        ll p1q0 = b * qpow(2, a) % mod;
        ll ans = (p0 + p1 + q0 - p0q0 - p1q0 + 2 * mod) % mod;
        // ll ans = qpow(2, a) % mod * (1 + (qpow(2, b) - 1) % mod + ((qpow(2, c) - 1) % mod * (b + d + 1) % mod) % mod + d) % mod << "\n";
        cout << ans << "\n";
    }
    return 0;
}
