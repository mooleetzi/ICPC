//整数分块儿
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const int maxn = 1e7 + 1000;
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
ll solve(ll n)
{
    ll ans = n + n / 2;
    for (ll i = 3; i <= n;)
    {
        ll to = n / (n / i);
        ans += (n / i) * (to - i + 1);
        i = to + 1;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int t;
    read(t);
    int tot = 0;
    while (t--)
    {
        int n;
        read(n);
        printf("Case %d: %lld\n", ++tot, solve(n));
    }
    return 0;
}
