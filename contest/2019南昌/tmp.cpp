#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
struct num
{
    ll x, y;
};
ll w;
num mul(num a, num b, ll p)
{
    num ans = {0, 0};
    ans.x = ((a.x * b.x % p + a.y * b.y % p * w % p) % p + p) % p;
    ans.y = ((a.x * b.y % p + a.y * b.x % p) % p + p) % p;
    return ans;
}

ll powwR(ll a, ll b, ll p)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = 1ll * ans % p * a % p;
        a = a % p * a % p;
        b >>= 1;
    }
    return ans % p;
}
ll powwi(num a, ll b, ll p)
{
    num ans = {1, 0};
    while (b)
    {
        if (b & 1)
            ans = mul(ans, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ans.x % p;
}

ll solve(ll n, ll p)
{
    n %= p;
    if (p == 2)
        return n;
    if (powwR(n, (p - 1) / 2, p) == p - 1)
        return -1; //不存在
    ll a;
    while (1)
    {
        a = rand() % p;
        w = ((a * a % p - n) % p + p) % p;
        if (powwR(w, (p - 1) / 2, p) == p - 1)
            break;
    }
    num x = {a, 1};
    return powwi(x, (p + 1) / 2, p);
}
const ll p1 = 262199973, p2 = 736044383;
const ll sqrt17 = 473844410, invsqrt17 = 559329360;
unordered_map<ll, ll> mp;
ll cal(ll n)
{
    if (mp.count(n))
        return mp[n];
    return mp[n] = (qpow(p1, n) - qpow(p2, n) + mod) % mod * invsqrt17 % mod;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    srand(time(0));
    int q = read<int>();
    ll n = read<ll>();
    ll pre = 0, res = 0;
    for (int i = 0; i < q; i++)
    {
        n ^= (pre * pre);
        pre = cal(n);
        res ^= pre;
    }
    writeln(res);
    return 0;
}