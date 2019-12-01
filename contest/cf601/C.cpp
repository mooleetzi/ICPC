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
vector<int> g[maxn];
unordered_map<int, int> mp;
inline void add(int x, int y, int z)
{
    g[x].emplace_back(y);
    g[x].emplace_back(z);
    g[y].emplace_back(x);
    g[y].emplace_back(z);
    g[z].emplace_back(x);
    g[z].emplace_back(y);
    mp[x]++;
    mp[y]++;
    mp[z]++;
}
vector<int> res;
int vis[maxn];
void search(int f, int s)
{
    res.clear();
    res.emplace_back(f);
    res.emplace_back(s);
    vis[f] = vis[s] = 1;
    int flag = 1;
    for (int i = 1; i <= n - 2 && flag; i++)
    {
        int sz = g[f].size();
        int q = 0;
        for (int j = 0; j < sz; j++)
        {
            int v = g[f][j];
            if (!vis[v])
            {
                res.emplace_back(v);
                f = s;
                s = v;
                vis[v] = 1;
                break;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 0; i < n - 2; i++)
    {
        int q = read<int>(), w = read<int>(), e = read<int>();
        add(q, w, e);
    }
    int f, s;
    for (int i = 1; i <= n; i++)
        if (mp[i] == 1)
        {
            f = i;
            for (int j = 0; j < g[f].size(); j++)
                if (mp[g[f][j]] == 2)
                    s = g[f][j];
            break;
        }
    search(f, s);
    for (int x : res)
        write(x), pblank;
    return 0;
}