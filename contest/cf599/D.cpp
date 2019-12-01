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
}
set<int> g[maxn], s;
int vis[maxn];
void bfs(int x)
{
    s.erase(x);
    queue<int> q;
    q.emplace(x);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (vis[now])
            continue;
        vis[now] = 1;
        for (auto it = s.begin(); it != s.end();)
        {
            int v = *it;
            int f = 1;
            if (g[now].find(v) == g[now].end())
                q.emplace(v), it = s.erase(it), f = 0;
            if (f)
                ++it;
        }
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), m = read<int>();
    for (int i = 1; i <= n; i++)
        s.emplace(i);
    for (int i = 0; i < m; i++)
    {
        int x = read<int>(), y = read<int>();
        g[x].emplace(y), g[y].emplace(x);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            bfs(i), ++res;
    writeln(res - 1);
    return 0;
}