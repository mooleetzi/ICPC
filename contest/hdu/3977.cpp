#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 1e6 + 10;
template <class T>
inline T read()
{
    int f = 1;
    T ret = 0;
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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
int pri[maxn], num[maxn], fac[maxn];
int ptot, ftot;
int prime[maxn], vis[maxn], pcnt;
struct mat
{
    ll f[2][2];
};
mat I = {1, 0, 0, 1}, A = {1, 1, 1, 0};
mat mul(const mat &a, const mat &b, ll mod)
{
    mat res;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            res.f[i][j] = 0;
            for (int k = 0; k < 2; k++)
                res.f[i][j] = (res.f[i][j] + a.f[i][k] * b.f[k][j] % mod) % mod;
        }
    return res;
}
mat qpow(mat a, ll n, ll mod)
{
    mat res = I;
    while (n)
    {
        if (n & 1)
            res = mul(res, a, mod);
        a = mul(a, a, mod);
        n >>= 1;
    }
    return res;
}
void init()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[pcnt++] = i;
        for (int j = 0; j < pcnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void getFac(ll n)
{
    ftot = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            fac[ftot++] = i;
            if (i * i != n)
                fac[ftot++] = n / i;
        }
    }
}
void getPri(ll n)
{
    ptot = 0;
    for (int i = 0; i < pcnt && prime[i] * prime[i] <= n; i++)
    {
        if (n % prime[i] == 0)
        {
            int c = 0;
            while (n % prime[i] == 0)
            {
                ++c;
                n /= prime[i];
            }
            pri[ptot] = prime[i];
            num[ptot++] = c;
        }
    }
    if (n > 1)
    {
        pri[ptot] = n;
        num[ptot++] = 1;
    }
}
ll qpow(ll a, ll n, ll p)
{
    a %= p;
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return res;
}
LL legendre(LL a, LL p)
{
    if (qpow(a, (p - 1) >> 1, p) == 1)
        return 1;
    else
        return -1;
}
ll solve(ll n)
{
    getPri(n);
    ll res = 1;
    for (int i = 0; i < ptot; i++)
    {
        ll tmp = 1;
        if (pri[i] == 2)
            tmp = 3;
        else if (pri[i] == 3)
            tmp = 8;
        else if (pri[i] == 5)
            tmp = 20;
        else
        {
            if (legendre(5, pri[i]) == 1)
                getFac(pri[i] - 1);
            else
                getFac(2 * (pri[i] + 1));
            sort(fac, fac + ftot);
            for (int j = 0; j < ftot; j++)
            {
                mat cur = qpow(A, fac[j] - 1, pri[i]);
                ll x = (cur.f[0][0] % pri[i] + cur.f[0][1] % pri[i]) % pri[i];
                ll y = (cur.f[1][0] % pri[i] + cur.f[1][1] % pri[i]) % pri[i];
                if (x == 1 && y == 0)
                {
                    tmp = fac[j];
                    break;
                }
            }
        }
        for (int k = 1; k < num[i]; k++)
            tmp *= pri[i];
        res = res / __gcd(res, tmp) * tmp;
    }
    return res;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    init();
    int t = read<int>();
    for (int cas = 1; cas <= t; ++cas)
    {
        n = read<int>();
        printf("Case #%d: %lld\n", cas, solve(n));
    }
    return 0;
}