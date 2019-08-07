//低位直接算，大于1000就截掉
//高位思想类似，不过需要用double，不然得不到答案(雾)
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const ll maxn = 1e6;
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
int qpow2(ll a, int b)
{
    int c = 1000;
    a %= c;
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
            if (ans >= c)
                ans %= c;
        }
        a *= a;
        if (a >= c)
            a %= c;
        b >>= 1;
    }
    return ans;
}
int qpow1(ld a, int b)
{
    ll c = 1e4;
    ld ans = 1; //ll会wa
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
            while (ans >= c)
                ans /= 10;
        }
        a *= a;
        while (a >= c)
            a /= 10;
        b >>= 1;
    }
    while (ans >= 1000)
    {
        ans /= 10;
    }
    return (int)ans;
}
int main(int argc, char const *argv[])
{
    int t;
    int tot = 0;
    read(t);
    while (t--)
    {
        ll n;
        int k;
        read(n), read(k);
        ll ff = n;
        int fa = qpow1(ff, k);
        ll llt = n;
        int la = qpow2(llt, k);
        printf("Case %d: %d %03d\n", ++tot, fa, la);
    }
    return 0;
}
