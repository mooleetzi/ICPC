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
struct Node
{
    int l, r, d;
    Node() {}
    Node(int _l, int rr, int dd) : l(_l), r(rr), d(dd) {}
    bool operator<(const Node &t) const
    {
        return l < t.l;
    }
} p[maxn];
ll a[maxn];
inline int judge(int cur)
{
    int time = 0, now = 0;
    for (int i = 1; i <= k; i++)
    {
        if (now >= p[i].r || cur >= p[i].d)
            continue;
        if (now < p[i].l - 1)
        {
            time += p[i].l - 1 - now;
            now = p[i].l - 1;
        }
        time += (p[i].r - now) * 3;
        now = p[i].r;
    }
    if (now < n + 1)
        time += n + 1 - now;
    return time <= t;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    m = read<int>(), n = read<int>(), k = read<int>(), t = read<int>();
    for (int i = 1; i <= m; i++)
        a[i] = read<int>();
    for (int i = 1; i <= k; i++)
        p[i].l = read<int>(), p[i].r = read<int>(), p[i].d = read<int>();
    sort(p + 1, p + 1 + k);
    int head = 1, tail = maxn, res = tail;
    while (head <= tail)
    {
        int mid = head + tail >> 1;
        if (judge(mid))
        {
            res = mid;
            tail = mid - 1;
        }
        else
            head = mid + 1;
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        if (a[i] >= res)
            ++ans;
    writeln(ans);
    return 0;
}