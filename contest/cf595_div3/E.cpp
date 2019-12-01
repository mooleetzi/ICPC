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
const int maxn = 2e5 + 10;
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
ll dp[maxn][2];
ll a[maxn], b[maxn], c;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), c = read<int>();
    for (int i = 1; i < n; i++)
        a[i] = read<ll>();
    for (int i = 1; i < n; i++)
        b[i] = read<ll>();
    dp[2][1] = c + b[1];
    dp[2][0] = a[1];
    for (int i = 3; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]) + a[i - 1];
        dp[i][1] = min(dp[i - 1][0] + c, dp[i - 1][1]) + b[i - 1];
    }
    for (int i = 1; i <= n; i++)
        write(min(dp[i][0], dp[i][1])), putchar(' ');
    return 0;
}