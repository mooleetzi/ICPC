/*
    u(lcm(i,j))=u(i)*u(j)*u(gcd(i,j))
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
int vis[maxn], prime[maxn], mu[maxn], pfac[maxn], pcnt, u[maxn];
ll ans[25];
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
    for (int i = 1; i < maxn; i++)
        for (int j = i; j < maxn; j += i)
            u[j] += mu[i] * mu[j / i];
}
ll solve()
{
    ll res = 0;
    if (n > m)
        swap(n, m);
    for (int d = 1; d <= n; d++)
    {
        ll tmp = u[d];
        ll t1 = 0, t2 = 0;
        for (int i = 1; i <= n / d; i++)
            t1 += mu[i * d];
        for (int i = 1; i <= m / d; i++)
            t2 += mu[i * d];
        res += t1 * t2 * tmp;
    }
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    int q = read<int>();
    while (q--)
    {
        n = read<int>(), m = read<int>();
        write(solve());
        puts("");
    }
    return 0;
}