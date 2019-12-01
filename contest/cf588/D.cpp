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
const int maxn = 1e4 + 10;
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
inline int f(ll x, ll y)
{
    while (x && y)
    {
        int t1 = x % 2, t2 = y % 2;
        if (t1 && !t2)
            return 1;
        x >>= 1, y >>= 1;
    }
    if (x && !y)
        return 1;
    return 0;
}
vector<ll> vec;
ll a[maxn], b[maxn];
unordered_map<ll, int> vis1, vis2;
unordered_map<ll, int> mp;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt","w", stdout);
#endif

    n = read<int>();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read<ll>();
        mp[a[i]]++;
        if (mp[a[i]] >= 2 && !vis1[a[i]])
            vis1[a[i]] = 1, vec.emplace_back(a[i]);
    }
    for (int i = 1; i <= n; i++)
        b[i] = read<ll>();
    ll ans = 0;
    int sz = vec.size();
    for (int i = 0; i < sz; i++)
    {
        ll t = vec[i];
        for (int j = 1; j <= n; j++)
            if (!vis2[j] && (t | a[j]) == t)
                ans += b[j], vis2[j] = 1;
    }
    writeln(ans);
    return 0;
}