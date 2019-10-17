/*
    列众数
*/
#include <algorithm>
#include <cctype>
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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
char s[maxn][maxn];
int score[maxn];
int ans = 0;
int t[6];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), m = read<int>();
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    for (int i = 0; i < m; i++)
        score[i] = read<int>();
    for (int i = 0; i < m; i++)
    {
        memset(t, 0, sizeof t);
        int res = 0;
        for (int j = 0; j < n; j++)
            ++t[s[j][i] - 'A'], res = max(res, t[s[j][i] - 'A']);
        ans += res * score[i];
    }
    write(ans);
    return 0;
}