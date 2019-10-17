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
const int maxn = 5e2 + 10;
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
int a[maxn], b[maxn];
int linkx[maxn], visy[maxn], mp[maxn][maxn];
int l, r;
int dfs(int u)
{
    for (int j = l; j <= r; j++)
        if (!visy[j] && mp[u][j])
        {
            visy[j] = 1;
            if (linkx[j] == -1 || dfs(linkx[j]))
            {
                linkx[j] = u;
                return 1;
            }
        }
    return 0;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), k = read<int>();
    for (int i = 0; i < n; i++)
        a[i] = read<int>();
    for (int i = 0; i < n; i++)
        b[i] = read<int>();
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= b[i]; j++)
            mp[i][j] = 1;
    }
    while (k--)
    {
        l = read<int>(), r = read<int>();
        fill(visy, visy + maxn, 1);
        memset(linkx, -1, sizeof linkx);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = l; j <= r; j++)
                visy[j] = 0;
            res += dfs(i);
        }
        writeln(res);
    }
    return 0;
}