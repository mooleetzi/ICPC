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
int flg[maxn], mu[maxn], p[maxn], tot;
void init()
{
    mu[1] = 1;
    for (int i = 2; i < maxn; ++i)
    {
        if (!flg[i])
            p[++tot] = i, mu[i] = -1;
        for (int j = 1; j <= tot && i * p[j] < maxn; ++j)
        {
            flg[i * p[j]] = 1;
            if (i % p[j] == 0)
            {
                mu[i * p[j]] = 0;
                break;
            }
            mu[i * p[j]] = -mu[i];
        }
    }
}
int solve()
{
    int res = 0;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            res += mu[i / __gcd(i, j) * j];
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
        n = read<int>(), m = read<int>();
        write(solve());
        puts("");
    }
    return 0;
}
