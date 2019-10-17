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
int mu[maxn], prime[maxn], vis[maxn];
int pcnt;
int pre[maxn];
void init()
{
    mu[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
        {
            prime[pcnt++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < pcnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
}
inline ll solve(int n, int m)
{
    ll res = 0;
    if (n > m)
        swap(n, m);
    for (int i = 1; i <= n; i++)
        res += (ll)mu[i] * (n / i) * (m / i);
    ll tmp = 0;
    for (int i = 1; i <= n; i++)
        tmp += (ll)mu[i] * (n / i) * (n / i);
    res -= tmp / 2;
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int t = read<int>();
    for (int cas = 1; cas <= t; ++cas)
    {
        n = read<int>(), n = read<int>(), m = read<int>(), m = read<int>();
        k = read<int>();
        ll res = 0;
        if (k)
            res = solve(n / k, m / k);
        printf("Case %d: %lld\n", cas, res);
    }
    return 0;
}