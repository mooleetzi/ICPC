/*
    先将不可变部分找出来，注意在题目给定的可见区域的下一行也是一定的，也算不可变区域
    然后就得到一个式子(k-1)^(nx)*cur=pre(mod 1e8+7),其中cur为已经求得种类数目，pre是题目给定
    然后利用乘法逆元将cur除到右边，再利用大步小步算法离散对数取模得到x值，将x值加上之前求得的行数即为答案
    改用mod就用mod，别xjb用-。

 */
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
const int maxn = 5100;
const int mod = 100000007;
ll n, k, m, pre, r;
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
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
struct node
{
    ll x, y;
} s[maxn];
bool cmp(node a, node b)
{
    if (a.y == b.y)
        return a.x < b.x;
    else
        return a.y < b.y;
}
inline void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b != 0)
    {
        exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1, y = 0;
    }
}

inline ll inv(ll a)
{
    return qpow(a, mod - 2);
}
ll BSGS(ll a, ll b)
{
    ll m = (ll)sqrt(mod + 0.5);
    map<ll, ll> x;
    x[1] = 0;
    ll ans = 1;
    for (int i = 1; i <= m; i++)
    {
        ans = ans * a % mod;
        if (!x.count(ans))
            x[ans] = i;
    }
    ll pm = inv(qpow(a, m));
    for (int i = 0; i < m; i++)
    {
        if (x.count(b))
            return i * m + x[b];
        b = b * pm % mod;
    }
    return -1;
}
ll solve()
{
    ll cur = 1;
    ll ans = 1;
    ll k1 = n; //可以为k种选择的格子数目
    for (int i = 0; i < m; i++)
    {
        if (s[i].x == 1)
            k1--;
        if (s[i].x != r)
        {
            if (i + 1 < m && s[i + 1].y == s[i].y)
            {
                if (s[i].x + 1 != s[i + 1].x)
                {
                    k1++;
                }
            }
            else
                k1++;
        }
    }
    cur = cur * qpow(k, k1) % mod;
    cur = cur * qpow(k - 1, n * r - k1 - m) % mod;
    if (cur == pre)
        return r;
    k1 = 0;
    for (int i = 0; i < m; i++)
    {
        if (s[i].x == r)
            k1++;
    }
    cur = cur * qpow(k, k1) % mod;
    cur = cur * qpow(k - 1, n - k1) % mod;
    if (cur == pre)
        return r + 1;
    //开始可变全为k-1部分
    pre *= inv(cur);
    pre %= mod;
    k = qpow(k - 1, n);
    r += BSGS(k, pre);
    return r + 1;
}
int main(int argc, char const *argv[])
{
    int t;
    read(t);
    // scanf("%d", &t);
    int tot = 0;
    while (t--)
    {
        r = 1;
        read(n), read(k), read(m), read(pre);
        // scanf("%lld %lld %lld %lld", &n, &k, &m, &pre);
        for (int i = 0; i < m; i++)
        {
            read(s[i].x), read(s[i].y);
            // scanf("%d%d", &s[i].x, &s[i].y);
            r = max(s[i].x, r);
        }
        sort(s, s + m, cmp);
        printf("Case %d: %lld\n", ++tot, solve());
    }
    return 0;
}
