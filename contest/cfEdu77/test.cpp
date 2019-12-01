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
int n, m, k, t;
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
int rm[maxn];
ll a[maxn], anum[maxn];
vector<int> d;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    m = read<int>(), n = read<int>(), k = read<int>(), t = read<int>();
    for (int i = 1; i <= m; i++)
    {
        a[i] = read<int>();
        ++anum[a[i]];
    }
    for (int i = 1; i < maxn; i++)
        anum[i] += anum[i - 1];
    for (int i = 1; i <= k; i++)
    {
        int l = read<int>(), r = read<int>(), di = read<int>();
        rm[di] = max(rm[di], r);
        d.emplace_back(di);
    }
    for (int i = maxn - 2; i >= 1; i--)
        rm[i] = max(rm[i], rm[i + 1]);
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()));
    int sz = d.size();
    // cout << sz << "..\n";
    int maxx = 0;
    int res = 0;
    for (int i = 0; i < sz; i++)
    {
        int cur = rm[d[i]];
        if (cur * 2 + n <= t)
        {
            maxx = d[i];
            if (i == 0)
                res = 1;
            else
                res = d[i - 1];
            break;
        }
    }
    if (!res)
        res = 1;
    writeln(anum[maxx] - anum[res - 1]);
    return 0;
}