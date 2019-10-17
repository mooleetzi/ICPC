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
P side[4];
int cur[4];
inline int judge()
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
        sum += cur[i];
    for (int i = 0; i < 4; i++)
        if (cur[i] >= sum - cur[i])
            return 0;
    return 1;
}
int dfs(int idx)
{
    if (idx == 4)
        return judge();
    int res = 0;
    cur[idx] = side[idx].first;
    res += dfs(idx + 1);
    if (side[idx].first != side[idx].second)
    {
        cur[idx] = side[idx].second;
        res += dfs(idx + 1);
    }
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        for (int i = 0; i < 4; i++)
            side[i].first = read<int>(), side[i].second = read<int>();
        write(dfs(0));
        puts("");
    }
    return 0;
}
