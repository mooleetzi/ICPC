/*
    最大独立集
    |V|-maxMatch
*/
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
int n, m, k;
const int maxn = 1e2 + 30;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
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
int g[maxn][maxn], llink[maxn], visr[maxn];
int find(int u)
{
    for (int i = 1; i <= n; i++)
    {
        if (g[u][i] && !visr[i])
        {
            visr[i] = 1;
            if (llink[i] == -1 || find(llink[i]))
            {
                llink[i] = u;
                return 1;
            }
        }
    }
    return 0;
}
int maxMatch()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(visr, 0, sizeof visr);
        res += find(i);
    }
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(llink, -1, sizeof llink);
        memset(g, 0, sizeof g);
        for (int i = 1; i <= m; i++)
        {
            int _, __;
            cin >> _ >> __;
            g[_][__] = 1;
        }
        cout << n - maxMatch() << "\n";
    }
    return 0;
}