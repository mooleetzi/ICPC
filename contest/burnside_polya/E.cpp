/*
    圆环置换群2n个
        旋转(n种)：旋转i(1=<i<=n)个球
        翻转(n种)：分奇偶考虑
            奇:任选一个顶点作对称轴翻转，n种
            偶：n/2组相对顶点作对称轴，n/2组相对边作对称轴
    不同颜色的放入等价类的划分:个数限制的不同球放入不同盒子，不允许空盒
*/
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
int n, m, k;
const int maxn = 1e5 + 10;
int a[7], b[7];
ll c[41][41];
inline void init()
{
    for (int i = 0; i <= 40; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
}
inline ll C(ll n, ll m)
{
    return c[n][m];
}
inline ll doit(int k)
{
    memcpy(b, a, sizeof a);
    int group = 0;
    ll res = 1;
    for (int i = 1; i <= 3; i++)
    {
        if (b[i] % k)
            return 0;
        b[i] /= k;
        group += b[i];
    }
    for (int i = 1; i <= 3; i++)
    {
        res *= C(group, b[i]);
        group -= b[i];
    }
    return res;
}
inline ll solve(ll n)
{
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        res += doit(n / __gcd(n, i));
    }
    if (n & 1)
    {
        for (int i = 1; i <= 3; i++)
            if (a[i])
            {
                --a[i];
                res += n * doit(2);
                a[i]++;
            }
    }
    else
    {
        res += n / 2 * doit(2);
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
            {
                a[i]--, a[j]--;
                if (a[i] < 0 || a[j] < 0)
                {
                    ++a[i], ++a[j];
                    continue;
                }
                res += n / 2 * doit(2);
                ++a[i], ++a[j];
            }
    }
    return res / (2 * n);
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
    init();
    cin >> t;
    while (t--)
    {
        cin >> a[1] >> a[2] >> a[3];
        cout << solve(a[1] + a[2] + a[3]) << "\n";
    }
    return 0;
}
