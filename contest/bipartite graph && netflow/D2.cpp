/*
    有X就新添一行或一列
    最大匹配
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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int maxn = 110;
int llink[maxn], g[maxn][maxn];
char s[maxn][maxn];
bool visr[maxn];
int col, row;
int c[maxn][maxn], r[maxn][maxn];
int find(int u)
{
    for (int i = 1; i <= col; i++)
    {
        if (g[u][i])
        {
            if (!visr[i])
            {
                visr[i] = 1;
                if (llink[i] == -1 || find(llink[i]))
                {
                    llink[i] = u;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int maxMatch()
{
    int res = 0;
    for (int i = 1; i <= row; i++)
    {
        memset(visr, 0, sizeof visr);
        res += find(i);
    }
    return res;
}
int n;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++)
            cin >> s[i];
        row = col = 0;
        for (int i = 0; i < n; i++)
        {
            ++row;
            for (int j = 0; j < n; j++)
            {
                if (s[i][j] == '.')
                {
                    if (j && s[i][j - 1] == 'X')
                        r[i][j] = ++row;
                    else
                        r[i][j] = row;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            ++col;
            for (int j = 0; j < n; j++)
            {
                if (s[j][i] == '.')
                {
                    if (j && s[j - 1][i] == 'X')
                        c[j][i] = ++col;
                    else
                        c[j][i] = col;
                }
            }
        }
        memset(g, 0, sizeof g);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (s[i][j] == '.')
                    g[r[i][j]][c[i][j]] = 1;
        memset(llink, -1, sizeof llink);
        cout << maxMatch() << "\n";
    }
    return 0;
}
