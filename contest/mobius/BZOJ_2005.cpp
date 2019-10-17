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
int ptot, prime[maxn], vis[maxn], mu[maxn];
void init()
{
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prime[ptot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < ptot && i * prime[j] <= n; j++)
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
    for (int i = 1; i <= n; i++)
        mu[i] += mu[i - 1];
}
ll cal(int n, int m)
{
    ll res = 0;
    for (int i = 1, j; i <= n; i = j + 1)
    {
        j = min(n / (n / i), m / (m / i));
        res += (ll)(mu[j] - mu[i - 1]) * (n / i) * (m / i);
    }
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), m = read<int>();
    if (n > m)
        swap(n, m);
    init();
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += i * cal(n / i, m / i);
    writeln(2 * res - (ll)n * m);
    return 0;
}
