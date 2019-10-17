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
ll mp[12][maxn];
inline int cal(int x, int b)
{
    int sum = 0;
    while (x)
    {
        sum += x % b;
        x /= b;
    }
    return sum;
}
inline void init()
{
    for (int j = 2; j <= 10; j++)
        for (int i = 1; i <= 1e6; i++)
            mp[j][i] = cal(i, j);
    for (int i = 2; i <= 10; i++)
        for (int j = 1; j <= 1e6; j++)
            mp[i][j] += mp[i][j - 1];
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    init();
    int t = read<int>();
    for (int cas = 1; cas <= t; cas++)
    {
        n = read<int>(), k = read<int>();
        printf("Case #%d: %lld\n", cas, mp[k][n]);
    }
    return 0;
}