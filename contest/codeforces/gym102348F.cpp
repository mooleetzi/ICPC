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
int a[maxn];
ll dp1[maxn], dp2[maxn];
ll ans1, ans2, ans3;
vector<int> z;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 1; i <= n; i++)
        a[i] = read<int>();

    for (int i = 1; i <= n; i++)
    {
        if (a[i] > 0)
        {
            dp1[i] = dp1[i - 1] + 1, dp2[i] = dp2[i - 1];
        }
        else if (a[i] < 0)
        {
            dp1[i] = dp2[i - 1];
            dp2[i] = dp1[i - 1] + 1;
        }
        else if (a[i] == 0)
        {
            // z.emplace_back(i);
            dp1[i] = dp2[i] = 0;
        }
        ans1 += dp1[i], ans3 += dp2[i];
    }
    printf("%lld %lld %lld\n", ans3, 1LL * n * (n + 1) / 2 - ans1 - ans3, ans1);
    return 0;
}