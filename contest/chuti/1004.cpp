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
template <typename T>
void _write(const T &t)
{
    write(t);
}
template <typename T, typename... Args>
void _write(const T &t, Args... args)
{
    write(t), pblank;
    _write(args...);
}
template <typename T, typename... Args>
inline void write_line(const T &t, const Args &... data)
{
    _write(t, data...);
    puts("");
}
ll v[maxn], t[maxn], pos[maxn];
ll dp[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 1; i <= n; i++)
        v[i] = read<int>(), v[i] += v[i - 1];
    for (int i = 1; i <= n; i++)
        t[i] = read<int>();
    int l = 1, r = n;
    memset(dp, 0x3f, sizeof(dp));
    while (l <= r)
    {
        while (v[n] - v[r - 1] < v[l])
            r--;
        if (v[n] - v[r - 1] == v[l])
            pos[l] = r;
        if (pos[l] == r)
            dp[l] = t[l] + t[n - r + 1];
        ++l;
    }
    ll res = t[n];
    for (int i = 1; i <= n >> 1; i++)
    {
        int p1 = pos[i];
        if (!p1)
            continue;
        for (int j = 1; j < i; j++)
        {
            int p2 = pos[j];
            if (!p2)
                continue;
            dp[i] = min(dp[i], dp[j] + t[p2 - p1] + t[i - j]);
        }
        res = min(res, dp[i] + t[p1 - i - 1]);
    }
    writeln(res);
}