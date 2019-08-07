//分块儿+矩阵快速幂
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
const int mod = 1e9 + 7;
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
ll tmp[3][3];
ll a, b, c, d, p, n;
void mul(ll a[][3], ll b[][3])
{
    ll ans[3][3];
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                ans[i][j] = (ans[i][j] + a[i][k] % mod * b[k][j] % mod) % mod;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = ans[i][j];
}
void qpow(ll a[][3], int b)
{
    ll ans[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i == j)
                ans[i][j] = 1;
            else
                ans[i][j] = 0;
    while (b)
    {
        if (b & 1)
            mul(ans, a);
        mul(a, a);
        b >>= 1;
    }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = ans[i][j];
}
void init(ll tmp[][3])
{
    tmp[0][0] = d;
    tmp[0][1] = c;
    tmp[0][2] = 0;
    tmp[1][0] = 1;
    tmp[1][1] = 0;
    tmp[1][2] = 0;
    tmp[2][0] = 0;
    tmp[2][1] = 0;
    tmp[2][2] = 1;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    // read(t);
    cin >> t;
    while (t--)
    {
        // read(a), read(b), read(c), read(d), read(p), read(n);
        cin >> a >> b >> c >> d >> p >> n;
        ll ans = 0;
        int f = 0;
        if (n == 1)
            ans = a;
        else if (n == 2)
            ans = b;
        else
        {
            for (ll i = 3; i <= n; i++)
            {
                if (p / i)
                {
                    init(tmp);
                    ll from = i;
                    ll to = p / (p / from);
                    to = min(n, to);
                    tmp[0][2] = p / from;
                    qpow(tmp, to - from + 1);
                    i = to;
                    ll t1 = (tmp[1][0] * b + tmp[1][1] * a + tmp[1][2]) % mod;
                    ll t2 = (tmp[0][0] * b + tmp[0][1] * a + tmp[0][2]) % mod;
                    a = t1;
                    b = t2;
                    ans = b;
                }
                else
                {
                    init(tmp);
                    qpow(tmp, n - i + 1);
                    ans = (tmp[0][0] * b + tmp[0][1] * a + tmp[0][2]) % mod;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
