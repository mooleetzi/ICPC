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
const int maxn = 2e2 + 10;
const int maxe = 1e5 + 100;
int n, m, k;
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
inline void writeln(T n)
{
    write(n);
    puts("");
}
struct node
{
    int init, idx;
    bool operator<(const node &x) const
    {
        return init < x.init;
    }
} r[maxn];

int dis[maxn][maxn][maxn];
inline void init()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j][k] = min(dis[i][k][k - 1] + dis[k][j][k - 1], dis[i][j][k - 1]);
    }
}
int mp[maxe];
inline int dijk(int s, int t, int ww)
{
    int x = r[s].idx;
    int y = r[t].idx;
    int z = mp[ww];
    return dis[x][y][z];
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    for (int cas = 1; cas <= t; cas++)
    {
        printf("Case #%d:\n", cas);
        n = read<int>(), m = read<int>();
        memset(mp, 0, sizeof mp);
        for (int i = 1; i <= n; i++)
        {
            int x = read<int>();
            r[i].init = x;
            r[i].idx = i;
        }
        sort(r + 1, r + 1 + n);
        for (int i = 1; i <= n; i++)
            mp[r[i].init] = i;
        for (int i = 1; i < maxe; i++)
            if (!mp[i])
                mp[i] = mp[i - 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                int x = r[i].idx;
                int y = r[j].idx;
                dis[x][y][0] = read<int>();
            }
        init();
        while (m--)
        {
            int u = read<int>(), v = read<int>(), w = read<int>();
            writeln(dijk(u, v, w));
        }
    }
    return 0;
}
