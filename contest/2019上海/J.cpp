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
const int mod = 1e9 + 7;
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
int dp[maxn], ans[maxn];
int w[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        n = read<int>();
        int ww = 0;
        for (int i = 1; i <= n; i++)
            w[i] = read<int>(), ww += w[i], ans[i] = 0;
        memset(dp, 0, sizeof(int) * (ww + 501));
        sort(w + 1, w + 1 + n);
        dp[0] = 1;
        for (int i = n; i >= 1; i--)
            for (int j = ww; j >= 0; j--)
            {
                // if (!dp[j])
                //     continue;
                dp[j + w[i]] += dp[j];
                dp[j + w[i]] %= mod;
                int u = j + w[i];
                int v = ww - u;
                if (u >= v && u - w[i] <= v)
                    ans[i] += dp[j];
                ans[i] %= mod;
            }
        ll res = 0;
        for (int i = 1; i <= n; i++)
            res += ans[i];
        writeln(res % mod);
    }
    return 0;
}