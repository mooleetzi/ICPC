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
int fa[1010][1010], Fa[1010 * 1010];
int idx[1010][1010];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int find(int *f, int x)
{
    return f[x] == x ? x : f[x] = find(f, f[x]);
}
void merge(int *f, int x, int y)
{
    x = find(f, x), y = find(f, y);
    if (x != y)
        f[x] = y;
}
int res;
void handle(int x, int y)
{
    static int tot = 0;
    idx[x][y] = ++tot, Fa[tot] = tot;
    ++res;
    merge(fa[x], y, y + 1);
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx && ty && tx <= n && ty <= m && idx[tx][ty])
        {
            int u = find(Fa, tot), v = find(Fa, idx[tx][ty]);
            if (u != v)
                --res, Fa[u] = v;
        }
    }
}
void draw(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i <= x2; i++)
        for (int j = find(fa[i], y1); j <= y2; j = find(fa[i], j))
            handle(i, j);
}
char s[1010][1010];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    fastIO;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> s[i] + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m + 1; j++)
            fa[i][j] = j;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s[i][j] == '1')
                handle(i, j);
    cin >> k;
    while (k--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        draw(x1, y1, x2, y2);
        writeln(res);
    }
    return 0;
}