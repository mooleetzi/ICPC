/*
    计算每行每列的*值，n+m-1-r[i]-c[j]+a[i][j]取个min
    a[i][j]表示(i,j)是否为*，是的话会多减一个所以需要加回来
*/
#pragma optmize(2)
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
const int maxn = 5e4 + 10;
const int mod = 998244353;
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
int r[maxn], c[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {

        n = read<int>(), m = read<int>();
        int a[n + 1][m + 1];
        memset(r, 0, sizeof r);
        memset(c, 0, sizeof c);
        memset(a, 0, sizeof a);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char ch = getchar();
                if (ch == '*')
                    ++r[i], ++c[j], a[i][j] = 1;
            }
            getchar();
            // cout << "r" << i << ": " << r[i] << "\n";
        }

        int res = 1e9;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res = min(n + m - 1 - r[i] - c[j] + a[i][j], res);
        write(res);
        puts("");
    }
    return 0;
}