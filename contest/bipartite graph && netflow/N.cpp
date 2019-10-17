/*
    最大匹配裸题
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
const int maxn = 5e2 + 10;
int g[maxn][maxn], visr[maxn], llink[maxn];
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
inline void init()
{
    memset(g, 0, sizeof g);
    memset(llink, -1, sizeof llink);
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
    while (cin >> n >> k)
    {
        init();
        for (int i = 1; i <= k; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x][y] = 1;
        }
        cout << maxMatch() << "\n";
    }
    return 0;
}
