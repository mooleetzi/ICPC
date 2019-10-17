/*
    二进制枚举
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
int n;
int a[10][10], b[10][10];
int judge(int t)
{
    int f = n & 1;
    memcpy(b, a, sizeof a);
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int idx = (i - 1) * n + j;
            if (t & (1 << (idx - 1)))
            {
                if (b[i][j] != -1)
                {
                    ++res;
                    b[i][j] = 1;
                }
                else
                    return 0;
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (b[i][j] == 1)
            {
                for (int k = i + 1; k <= n; k++)
                    if (b[k][j] == 1)
                        return 0;
                    else if (b[k][j] == -1)
                        break;
                for (int k = i - 1; k >= 1; k--)
                    if (b[k][j] == 1)
                        return 0;
                    else if (b[k][j] == -1)
                        break;
                for (int k = j + 1; k <= n; k++)
                    if (b[i][k] == 1)
                        return 0;
                    else if (b[i][k] == -1)
                        break;
                for (int k = j - 1; k >= 1; k--)
                    if (b[i][k] == 1)
                        return 0;
                    else if (b[i][k] == -1)
                        break;
            }
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
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                char c;
                cin >> c;
                if (c == '.')
                    a[i][j] = 0;
                else
                    a[i][j] = -1;
            }
        int k = 1 << (n * n);
        int res = 0;
        for (int i = 0; i < k; i++)
        {
            res = max(res, judge(i));
        }
        cout << res << "\n";
    }
    return 0;
}
