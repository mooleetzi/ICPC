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
const ll mod = 10000007;
const ll inv2 = 7486194;
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
int vis[maxn], prime[maxn], pcnt, num[maxn];
ll qpow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll f(ll n, int p)
{
    if (n == 0)
        return 0;
    return f(n / p, p) + n / p;
}
void init()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[pcnt++] = i;
        for (int j = 0; j < pcnt && i * prime[j] <= maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    init();
    while (~scanf("%d", &n) && n)
    {
        memset(num, 0, sizeof(int) * (n + 1));
        for (int i = 2; i <= n; i++)
            if (!vis[i])
                num[i] = f(n, i);
        ll res = 1;
        for (int i = 2; i <= n; i++)
            if (num[i])
            {
                if (num[i] & 1)
                    res = res * ((num[i] + 1) >> 1) * (num[i] + 2) % mod;
                else
                    res = res * ((num[i] + 2) >> 1) * (num[i] + 1) % mod;
            }
        writeln(res);
    }
    return 0;
}