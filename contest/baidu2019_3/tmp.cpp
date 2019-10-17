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
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, int> P;
int n, m, k;
const int maxn = 1e3 + 10;
ll a[maxn][maxn], d[maxn][maxn];
const ll inf = 0x3f3f3f3f * (ll)maxn;
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
ll solve()
{
    ll res = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] > a[i][k] + a[k][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                    d[i][j] = k;
                }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            res += d[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << d[i][j] << " ";
        cout << "\n";
    }
    return res % 998244353;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = i == j ? 0 : inf, d[i][j] = inf;
        n = read<int>(), m = read<int>();
        for (int i = 1; i <= m; i++)
        {
            int x = read<int>();
            int y = read<int>();
            int z = read<int>();
            a[x][y] = a[y][x] = min(a[y][x], (ll)z);
            d[x][y] = d[y][x] = 0;
        }
        write(solve());
        puts("");
    }
    return 0;
}
