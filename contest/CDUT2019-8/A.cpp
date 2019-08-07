#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const int maxn = 3e5 + 10;
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
ll fac[maxn], inv[maxn];
void init()
{
    fac[0] = fac[1] = 1;
    inv[0] = inv[1] = 1;
    for (ll i = 2; i < maxn; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    }
    for (ll i = 2; i < maxn; i++)
        inv[i] = inv[i - 1] * inv[i] % mod;
}
ll C(ll x, ll y)
{
    if (y > x)
        return 0;
    if (y == 0 || x == 0)
        return 1;
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    init();
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        ll ans = 0;
        if (k == 0)
            ans = 1;
        else if ((n - 1) * m < k)
            ans = 0;
        else
        {
            int c = min(k / n, m);
            for (int i = 0; i <= c; i++)
            {
                if (i % 2 == 0)
                    ans = (ans + C(m, i) * C(k - i * n + m - 1, m - 1) % mod) % mod;
                else
                    ans = (ans - C(m, i) * C(k - i * n + m - 1, m - 1) % mod + mod) % mod;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
