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
const int maxn = 1e5 + 10;
const int mod = 998244353;
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
struct mat
{
    ll tmp[2][2];
    mat()
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                tmp[i][j] = 0;
    }
};
mat mul(const mat &a, const mat &b)
{
    mat res;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                res.tmp[i][j] = (res.tmp[i][j] + a.tmp[i][k] * b.tmp[k][j] % mod) % mod;
    return res;
}
mat qpow(mat a, ll n)
{
    mat res;
    res.tmp[0][0] = res.tmp[1][1] = 1;
    while (n)
    {
        if (n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}
unordered_map<ll, ll> mp;
inline ll cal(ll n)
{
    if (mp.count(n))
        return mp[n];
    mat m;
    m.tmp[0][0] = 3, m.tmp[0][1] = 2;
    m.tmp[1][0] = 1;
    m = qpow(m, n - 1);
    return mp[n] = m.tmp[0][0] % mod;
}
void init()
{
    ll a = 0, b = 1;
    for (int i = 0; i < 1e6; i++)
    {
        mp[i] = a;
        ll t = b;
        b = (3 * b % mod + 2 * a % mod) % mod;
        a = t;
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    ll n = read<ll>(), q = read<ll>();
    ll pre = q, res = 0, tres = 0;
    for (int i = 0; i < n; i++)
    {
        pre ^= (tres * tres);
        tres = cal(pre);
        res ^= tres;
    }
    writeln(res);
    return 0;
}