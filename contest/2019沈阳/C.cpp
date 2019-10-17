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
const int maxn = 1e3 + 10;
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
struct node
{
    int p, c;
    bool operator<(const node &t) const
    {
        if (p * 1LL * t.c == c * 1LL * t.p)
            return p < t.p;
        return p * 1LL * t.c < c * 1LL * t.p;
    }
} a[maxn];
ll dp[maxn * 100];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i].p, &a[i].c);
        }
        for (int i = 1; i <= m + 1e4; i++)
            dp[i] = 1e14;
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = a[i].c; j <= m + 1e4; j++)
                dp[j] = min(dp[j], dp[j - a[i].c] + a[i].p);
        ll r1 = 1e14, r2 = 0;
        for (int i = m + 1e4; i >= m; i--)
            if (dp[i] < r1)
            {
                r1 = dp[i];
                r2 = i;
            }
        printf("%lld %lld\n", r1, r2);
    }
    return 0;
}