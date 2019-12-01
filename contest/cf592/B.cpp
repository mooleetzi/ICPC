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
int mp[2][1010];
int vis[2][1010];
int cur;
inline int judge(int x, int y)
{
    if (x >= 0 && x <= 1 && y && y <= n && !vis[x][y])
        return 1;
    return 0;
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    ++cur;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        n = read<int>();
        for (int i = 1; i <= n; i++)
            mp[0][i] = mp[1][i] = getchar() - '0', vis[0][i] = vis[1][i] = 0;
        getchar();
        int res = 0, pl = 0, pr = 0;
        for (int i = 1; i <= n; i++)
            if (mp[0][i] == 1)
                pl = i;
        for (int i = n; i >= 1; i--)
            if (mp[0][i] == 1)
                pr = i;
        if (!pl)
            res = n;
        else
            res = max(pl * 2, (n - pr + 1) * 2);
        writeln(res);
    }
    return 0;
}