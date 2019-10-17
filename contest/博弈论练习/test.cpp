#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
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
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 13;
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
int g[maxn][maxn], fa[maxn];
int dp[1 << maxn][maxn];
inline int find(int u)
{
    if (fa[u] == u)
        return u;
    return fa[u] = find(fa[u]);
}
inline void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        fa[y] = x;
}
inline void init()
{
    for (int i = 1; i < maxn; i++)
        fa[i] = i;
    memset(g, 0, sizeof g);
    memset(dp, 0, sizeof dp);
    for (int i = 1; i < maxn; i++)
        dp[1 << (i - 1)][i] = 1;
}
inline int check(int x)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (x & (1 << (i - 1)))
            ++res;
    return res > 2;
}
inline int lowbit(int x)
{
    for (int i = 1; i < maxn; i++)
        if (x & (1 << (i - 1)))
            return i;
    return 0;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        n = read<int>(), m = read<int>();
        init();
        for (int i = 0; i < m; i++)
        {
            int x = read<int>(), y = read<int>();
            g[x][y] = g[y][x] = 1;
            merge(x, y);
        }
        unordered_set<int> s;
        s.clear();
        for (int i = 1; i <= n; i++)
            s.emplace(find(i));
        int f = s.size() == 1;
        int res = 0;
        if (f)
        {
            int tot = 1 << n;
            for (int i = 1; i < tot; i++)
            {
                int st = lowbit(i);
                for (int j = st; j <= n; j++)
                {
                    if (i & (1 << (j - 1)) && dp[i][j])
                    {
                        for (int k = st; k <= n; k++)
                            if (!(i & (1 << (k - 1))) && g[j][k])
                            {
                                dp[i | (1 << (k - 1))][k] += dp[i][j];
                                if (g[k][st] && check(i | (1 << (k - 1))))
                                    res += dp[i][j];
                            }
                    }
                }
            }
        }
        res >>= 1;
        if (!f || res < 2)
            puts("n");
        else if (res == 2)
            puts("y");
        else
            puts("y: there are at least three cycles");
    }
    return 0;
}