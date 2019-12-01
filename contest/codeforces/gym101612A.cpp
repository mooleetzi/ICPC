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
const int maxn = 1e6 + 10;
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
const int w[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
ll dp[maxn];
int main(int argc, char const *argv[])
{

    freopen("auxiliary.in", "r", stdin);
    freopen("auxiliary.out", "w", stdout);
    n = read<int>();
    for (int i = 1; i <= n; i++)
        dp[i] = -1e12;
    dp[0] = 0;
    for (int i = 0; i < 10; i++)
        for (int j = w[i]; j <= n; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    writeln(dp[n]);
    return 0;
}