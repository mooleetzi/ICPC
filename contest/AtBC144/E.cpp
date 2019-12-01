#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m;
ll k;
const int maxn = 2e5 + 10;
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
ll a[maxn], f[maxn];
inline int judge(ll x)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] * f[n - i + 1] > x)
        {
            ll tmp = a[i] * f[n - i + 1] - x;
            cnt += tmp / f[n - i + 1];
            if (tmp % f[n - i + 1])
                ++cnt;
        }
    return cnt <= k;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    k = read<ll>();
    for (int i = 1; i <= n; i++)
        a[i] = read<ll>();
    for (int i = 1; i <= n; i++)
        f[i] = read<ll>();
    sort(a + 1, a + 1 + n);
    sort(f + 1, f + 1 + n);
    ll l = 0, r = 1e12 + 1;
    ll res = 0;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        if (judge(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    writeln(res);
    return 0;
}