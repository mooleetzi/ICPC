#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
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
#define pblank putchar(' ')
#define ll LL
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
ll n, m, k;
const int maxn = 1e5 + 10;
ll mod;
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
/*
    提交时用int128
    本地测试用ll
*/
#define INT __int128_t
// #define INT ll
inline ll mul(ll x, ll y)
{
    return INT(x) * y % mod;
}
struct mat
{
    ll t[2][2];
    mat() { memset(t, 0, sizeof t); }
    mat operator*(const mat &b)
    {
        mat res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                res.t[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    res.t[i][j] = (res.t[i][j] + mul(t[i][k], b.t[k][j])) % mod;
            }
        return res;
    }
};
mat qpow(mat base, ll n)
{
    mat res;
    res.t[0][0] = res.t[1][1] = 1;
    while (n)
    {
        if (n & 1)
            res = res * base;
        base = base * base;
        n >>= 1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        ll a, b;
        n = read<ll>();
        a = read<ll>(), b = read<ll>();
        mod = read<ll>();
        mat base;
        base.t[0][0] = mul(2, b);
        base.t[0][1] = (a - mul(b, b) + mod) % mod;
        base.t[1][0] = 1 % mod;
        mat res;
        res.t[0][0] = b % mod;
        res.t[1][0] = 1 % mod;
        n--;
        for (; n; n >>= 1, base = base * base)
            if (n & 1)
                res = base * res;
        writeln(res.t[0][0]);
    }
    return 0;
}