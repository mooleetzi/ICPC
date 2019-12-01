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
int a[maxn][4];
vector<int> g[maxn];
int ind[maxn], dfn[maxn], to[maxn];
int tot;
void dfs(int x, int p)
{
    dfn[x] = ++tot;
    to[tot] = x;
    int sz = g[x].size();
    for (int i = 0; i < sz; i++)
    {
        int y = g[x][i];
        if (y == p)
            continue;
        dfs(y, x);
    }
}
ll cur;
ll ans[maxn], tmp[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++)
            a[j][i] = read<int>();
    for (int i = 0; i < n - 1; i++)
    {
        int x = read<int>(), y = read<int>();
        g[x].emplace_back(y), g[y].emplace_back(x);
        ++ind[y], ++ind[x];
    }
    int f = 1, rt = -1;
    for (int i = 1; i <= n && f; i++)
        if (ind[i] > 2)
            f = 0;
        else if (ind[i] == 1)
            rt = i;
    if (!f)
    {
        puts("-1");
        return 0;
    }
    dfs(rt, 0);
    ll res = 1e16;
    int r[] = {1, 2, 3};
    do
    {
        cur = 0;
        for (int i = 0; i < 3; i++)
            cur += a[to[i + 1]][r[i]], tmp[i + 1] = r[i];
        for (int i = 4; i <= n; i++)
            cur += a[to[i]][6 - tmp[i - 1] - tmp[i - 2]], tmp[i] = 6 - tmp[i - 1] - tmp[i - 2];
        if (cur < res)
        {
            for (int i = 1; i <= n; i++)
                ans[to[i]] = tmp[i];
            res = cur;
        }
    } while (next_permutation(r, r + 3));
    writeln(res);
    for (int i = 1; i <= n; i++)
        write(ans[i]), pblank;
    return 0;
}