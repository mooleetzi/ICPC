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
#include <unordered_map>
#include <unordered_set>
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
int mu[maxn], prime[maxn], tot, vis[maxn], phi[maxn];
void init()
{
    mu[1] = 1, phi[1] = 1;
    for (int i = 1; i < maxn; i++)
        phi[i] = i;
    for (int i = 2; i < maxn; ++i)
    {
        if (!vis[i])
            prime[++tot] = i, mu[i] = -1, phi[i] = i - 1;
        for (int j = 1; j <= tot && i * prime[j] < maxn; ++j)
        {
            vis[i * prime[j]] = 1;
            phi[i * prime[j]] = phi[i * prime[j]] * (i - 1) / i;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i < maxn; i++)
        mu[i] += mu[i - 1];
    for (int i = 1; i < maxn; i++)
        phi[i] += phi[i - 1];
}
ll solve(int n, int m)
{
    ll res = 0, dec = 0;
    if (n > m)
        swap(n, m);
    res = phi[m], dec = phi[n];
    res -= dec / 2;
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
    int q = 0;
    while (t--)
    {
        int tt = read<int>();
        n = read<int>(), tt = read<int>(), m = read<int>(), k = read<int>();
        ll res = 0;
        if (k)
            res = solve(n / k, m / k);
        printf("Case %d: %I64d\n", ++q, res);
    }
    return 0;
}
