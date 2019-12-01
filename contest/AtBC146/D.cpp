#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
struct Node
{
    int idx, to, nxt;
} edg[maxn << 1];
int head[maxn], son[maxn];
int tot, rt, maxx = 0;
void add(int x, int y, int idx)
{
    edg[tot].idx = idx;
    edg[tot].to = y;
    edg[tot].nxt = head[x];
    head[x] = tot++;
}
int col[maxn];
void dfs(int u, int pre)
{
    for (int i = head[u]; ~i; i = edg[i].nxt)
    {
        int v = edg[i].to;
        if (v == pre)
            continue;
        dfs(v, u);
        ++son[u];
    }
    if (son[u] + (u != 1) > maxx)
    {
        maxx = son[u] + (u != 1);
        rt = u;
    }
}
void dfs2(int u, int fa, int pre)
{
    int x = 1;
    if (x == pre)
        ++x;
    if (x > maxx)
        x = 1;
    for (int i = head[u]; ~i; i = edg[i].nxt)
    {
        int v = edg[i].to;
        int num = edg[i].idx;
        if (col[num] || v == fa)
            continue;
        col[num] = x;
        ++x;
        if (x > maxx)
            x = 1;
        if (x == pre)
            ++x;
        if (x > maxx)
            x = 1;
    }
    for (int i = head[u]; ~i; i = edg[i].nxt)
    {
        int v = edg[i].to;
        int num = edg[i].idx;
        if (v != fa)
            dfs2(v, u, col[num]);
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    srand(time(nullptr));
    n = read<int>();
    memset(head, -1, sizeof(int) * (n + 1));
    for (int i = 0; i < n - 1; i++)
    {
        int x = read<int>(), y = read<int>();
        add(x, y, i);
        add(y, x, i);
    }
    dfs(1, 0);
    writeln(maxx);
    dfs2(rt, 0, 0);
    for (int i = 0; i < n - 1; i++)
        writeln(col[i]);
    return 0;
}