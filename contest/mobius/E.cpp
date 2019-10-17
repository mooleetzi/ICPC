/*
    枚举每个小于n的素数k，求gcd(i,j)==k的数目，累加
    gcd(i,j)==k用莫比乌斯反演
*/
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
const int maxn = 1e7 + 10;
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
int vis[maxn], prime[maxn], mu[maxn], pfac[maxn], pcnt;
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
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
}
ll f(int t)
{
    ll res = 0;
    for (int i = 1; i <= t; i++)
        res += (ll)mu[i] * (ll)(t / i) * (t / i);
    return res;
}
ll solve()
{
    ll res = 0;
    for (int i = 0; i < pcnt && prime[i] <= n; i++)
        res += f(n / prime[i]);
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    n = read<int>();
    write(solve());
    return 0;
}