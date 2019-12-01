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
const ll mod = 1000000007;
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
}
int h, w;
int r[maxn], c[maxn];
int mp[1010][1010];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    h = read<int>(), w = read<int>();
    for (int i = 1; i <= h; i++)
        r[i] = read<int>();
    for (int i = 1; i <= w; i++)
        c[i] = read<int>();
    for (int i = 1; i <= h; i++)
        if (r[i])
        {
            for (int j = 1; j <= r[i]; j++)
                mp[i][j] = 1;
            mp[i][r[i] + 1] = -1;
        }
        else
            mp[i][1] = -1;
    int f = 1;
    for (int i = 1; i <= w; i++)
        if (c[i])
        {
            for (int j = 1; j <= c[i]; j++)
            {
                if (mp[j][i] == -1)
                {
                    f = 0;
                    break;
                }
                mp[j][i] = 1;
            }
            if (mp[c[i] + 1][i] == 1)
            {
                f = 0;
                break;
            }
            else
                mp[c[i] + 1][i] = -1;
        }
        else
        {
            if (mp[1][i] == 1)
            {
                f = 0;
                break;
            }
            else
                mp[1][i] = -1;
        }
    ll res = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            if (!mp[i][j])
                ++res;
    ll ans = 1;
    ll base = 2;
    for (; res; res >>= 1)
    {
        if (res & 1)
            ans = ans * base % mod;
        base = base * base % mod;
    }
    if (f)
        writeln(ans);
    else
        puts("0");
    return 0;
}