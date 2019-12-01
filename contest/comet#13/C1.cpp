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
char s[1010][1010];
void draw(int x1, int y1, int x2, int y2)
{
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
            s[i][j] = '1';
}
int vis[1010][1010];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 1 && ty >= 1 && tx <= n && ty <= m && s[tx][ty] == '1' && !vis[tx][ty])
            dfs(tx, ty);
    }
}
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
    cin >> k;
    while (k--)
    {
        int x1, x2, y1, y2, res = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        draw(x1, y1, x2, y2);
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (s[i][j] == '1' && !vis[i][j])
                {
                    ++res;
                    dfs(i, j);
                }
        writeln(res);
    }
    return 0;
}