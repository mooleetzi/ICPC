/*
    倍数关系的单位元反演
    注意需要二维前缀和+数论分块
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
const int maxn = 5e5 + 10;
const int N = 20;
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
int mu[maxn], prime[maxn], vis[maxn], pf[maxn];
int pcnt;
int pre[N][maxn];
void init()
{
    pf[1] = 0;
    mu[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
        {
            prime[pcnt++] = i;
            pf[i] = 1;
            mu[i] = -1;
        }
        for (int j = 0; j < pcnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = 1;
            pf[i * prime[j]] = pf[i] + 1;
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
            pre[pf[i]][j] += mu[j / i];
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j < N; j++)
            pre[j][i] += pre[j - 1][i];
    for (int i = 1; i < maxn; i++)
        for (int j = 0; j < N; j++)
            pre[j][i] += pre[j][i - 1];
}
inline ll solve()
{
    if (k >= 20)
        return (ll)n * m;
    ll res = 0;
    for (int i = 1, j; i <= min(n, m); i = j + 1)
    {
        j = min(n / (n / i), m / (m / i));
        res += (ll)(pre[k][j] - pre[k][i - 1]) * (n / i) * (m / i);
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
    int t = read<int>();
    while (t--)
    {
        n = read<int>(), m = read<int>(), k = read<int>();
        writeln(solve());
    }
    return 0;
}