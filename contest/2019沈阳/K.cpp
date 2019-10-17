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
ll n, m, k;
const int maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
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
ll a[80], f[80];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        k = read<int>(), n = read<ll>();
        ll sum = 0;
        for (int i = 1; i <= k; i++)
            a[i] = read<int>();
        for (int i = 1; i <= k; i++)
            f[i] = read<int>();
        for (int i = 1; i <= k; i++)
            a[i] = (a[i] + a[i - 1]) % mod, f[i] = (f[i] + f[i - 1]) % mod;
        if (n <= k)
            writeln(a[n]);
        else
        {
            ll sum = a[k];
            ll t1 = n - k;
            ll cnt = t1 / k;
            sum = (sum + cnt % mod * f[k] % mod) % mod;
            ll t2 = t1 % k;
            sum = (sum + f[t2]) % mod;
            writeln(sum);
        }
    }
    return 0;
}