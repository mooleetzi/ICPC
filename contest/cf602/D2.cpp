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
P a[maxn];
struct Node
{
    int first, second, idx;
    Node(int a, int b, int c) : first(a), second(b), idx(c) {}
    Node() {}
    bool operator<(const Node &t) const
    {
        return first < t.first;
    }
} q[maxn];
inline int lowbit(int x)
{
    return x & (-x);
}
struct Ftree
{
    int c[maxn];
    void add(int x)
    {
        while (x < maxn)
        {
            ++c[x];
            x += lowbit(x);
        }
    }
    int query(int x)
    {
        int res = 0;
        while (x)
        {
            res += c[x];
            x -= lowbit(x);
        }
        return res;
    }
} tree;
int cmp(const P &a, const P &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
int res[maxn], tmp[maxn];
inline int judge(int x, int q)
{
    return tree.query(x) >= q;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 1; i <= n; i++)
    {
        int x = read<int>();
        a[i] = P(x, i);
    }
    for (int i = 1; i <= n; i++)
        tmp[i] = a[i].first;
    sort(a + 1, a + 1 + n, cmp);
    m = read<int>();
    for (int i = 1; i <= m; i++)
    {
        int k = read<int>(), p = read<int>();
        q[i] = Node(k, p, i);
    }
    sort(q + 1, q + 1 + m);
    for (int i = 1, j = 1; i <= m; i++)
    {
        while (j <= q[i].first)
            tree.add(a[j++].second);
        int l = 1, r = n, cur = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (judge(mid, q[i].second))
                cur = mid, r = mid - 1;
            else
                l = mid + 1;
        }
        res[q[i].idx] = tmp[cur];
    }
    for (int i = 1; i <= m; i++)
        writeln(res[i]);
    return 0;
}