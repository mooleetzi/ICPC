/*
    线性dp
    dp[i][1]代表到index为i这儿选择1队的最大值
    dp[i][2]代表index到i这儿选择2队的最大值
    则dp[i][1]=max{dp[1..i-1][2]}+a[i]
    dp[i][2]=max{dp[1..i-1][1]}+b[i]
    最后答案为max(dp[n][1],dp[n][2])
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
ll a[maxn], b[maxn];
ll dp[maxn][3], p[maxn][3];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 1; i <= n; i++)
        a[i] = read<ll>();
    for (int i = 1; i <= n; i++)
        b[i] = read<int>();
    p[1][1] = dp[1][1] = a[1];
    p[1][2] = dp[1][2] = b[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][1] = max(dp[i - 1][2], p[i - 1][2]) + a[i];
        dp[i][2] = max(dp[i - 1][1], p[i - 1][1]) + b[i];
        p[i][1] = max(p[i - 1][1], dp[i][1]);
        p[i][2] = max(p[i - 1][2], dp[i][2]);
    }
    write(max(dp[n][1], dp[n][2]));
    return 0;
}