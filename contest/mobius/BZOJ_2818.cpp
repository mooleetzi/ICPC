/*
    筛出n以内素数以及莫比乌斯函数
    对于每一个素数p用反演+分块儿求一次[gcd(i,j)=p],答案累加
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
        for (int j = 0; j < ptot && prime[j] * i <= n; j++)
        {
            vis[prime[j] * i] = 1;
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
ll cal(int n)
{
    ll res = 0;
    for (int i = 1, j; i <= n; i = j + 1)
    {
        j = n / (n / i);
        res += (ll)(mu[j] - mu[i - 1]) * (n / i) * (n / i);
    }
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    init();
    ll res = 0;
    for (int i = 0; i < ptot; i++)
        res += cal(n / prime[i]);
    write(res);
    return 0;
}
