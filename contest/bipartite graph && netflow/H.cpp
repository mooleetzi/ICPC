/*
    给一个只含0/1的矩阵，判断需要最少交换哪些行列变为对角线全1
    最大匹配，输出路径
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
const int maxn = 110;
int g[maxn][maxn], visr[maxn], llink[maxn], a[maxn][maxn];
int n;
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
int maxMacth()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(visr, 0, sizeof visr)
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
    while (cin >> n)
    {
        memset(llink, -1, sizeof llink);
        memset(g, 0, sizeof g);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> g[i][j];
        int mm = maxMacth();
        if (mm != n)
        {
            cout << "-1\n";
            continue;
        }
        else
        {
            vector<pair<int, int>> v;
            v.clear();
            int res = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (llink[j] == i && i != j)
                    {
                        v.push_back(make_pair(i, j));
                        swap(llink[i], llink[j]);
                        ++res;
                        // break;
                    }
                }
            }
            cout << res << "\n";
            for (int i = 0; i < res; i++)
                cout << "C " << v[i].first << " " << v[i].second << "\n";
        }
    }
    return 0;
}
