#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ext/rope>
#include <iostream>
#include <map>
#include <numeric>
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
#define pblank putchar(' ')
#define ll LL
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
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
unordered_map<int, int> mp;
int prime[maxn], vis[maxn], pcnt;
int a[maxn], b[maxn], c[maxn], d[maxn];
void init()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[pcnt++] = i;
        for (int j = 0; j < pcnt && prime[j] * i < maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
ll qpow(ll a, int n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    init();
    n = read<int>(), k = read<int>();
    for (int i = 1; i <= n; i++)
        a[i] = read<int>();
    for (int i = 1; i <= n; i++)
    {
        if (mp.count(a[i]))
        {
            b[i] = b[mp[a[i]]];
            c[i] = c[mp[a[i]]];
            continue;
        }
        int newcur = 1, tocur = 1;
        int tmp = a[i];
        int f = 1;
        for (int i = 0; i < pcnt && prime[pcnt] < tmp; i++)
            if (tmp % prime[i] == 0)
            {
                int now = 0;
                while (tmp % prime[i] == 0)
                {
                    tmp /= prime[i];
                    ++now;
                }
                now %= k;
                if (now)
                {
                    newcur *= qpow(prime[i], now);
                    int p = 1, flag = 1;
                    for (int j = 1; j <= k - now; j++)
                    {
                        p = p * prime[i];
                        if (p > 1e5)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag)
                        tocur *= p;
                    else
                        f = 0;
                }
            }
        if (tmp > 1)
        {
            newcur *= tmp;
            int p = 1, flag = 1;
            for (int j = 1; j <= k - 1; j++)
            {
                p = p * tmp;
                if (p > 1e5)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                tocur *= p;
            else
                f = 0;
        }
        b[i] = newcur;
        if (f)
            c[i] = tocur;
        else
            c[i] = -1;
        mp[a[i]] = i;
    }
    ll res = 0;
    for (int i = n; i >= 1; i--)
    {
        res += d[c[i]];
        d[b[i]]++;
    }
    writeln(res);
    return 0;
}