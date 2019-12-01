/*
    蛇形走位
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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
set<int> xi[maxn], yi[maxn], xd[maxn], yd[maxn];
int x, y;
int l, r, u, d, dic;
void init()
{
    x = y = 1;
    dic = 0;
    l = u = 0;
    r = m + 1, d = n + 1;
}
ll solve()
{
    ll cnt = 1;
    while (1)
    {
        if (dic == 0)
        {
            int cur = *xi[x].upper_bound(y);
            cur = min(cur, r);
            if (cur - y == 1)
                return cnt;
            cnt += cur - y - 1;
            y = cur - 1;
            u = max(x, u); //右是由上转移而来，更新上边界
        }
        else if (dic == 1)
        {
            int cur = *yi[y].upper_bound(x);
            cur = min(cur, d);
            if (cur - x == 1)
                return cnt;
            cnt += cur - x - 1;
            x = cur - 1;
            r = min(r, y); //下是由右转移而来，更新右边界
        }
        else if (dic == 2)
        {
            int cur = -*xd[x].upper_bound(-y);
            cur = max(cur, l);
            if (y - cur == 1)
                return cnt;
            cnt += y - cur - 1;
            y = cur + 1;
            d = min(d, x);
        }
        else if (dic == 3)
        {
            int cur = -*yd[y].upper_bound(-x);
            cur = max(cur, u);
            if (x - cur == 1)
                return cnt;
            cnt += x - cur - 1;
            x = cur + 1;
            l = max(l, y);
        }
        dic++;
        if (dic == 4)
            dic = 0;
    }
    return cnt;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), m = read<int>();
    k = read<int>();
    for (int i = 1; i <= n; i++)
        xi[i].emplace(0), xi[i].emplace(m + 1), xd[i].emplace(0), xd[i].emplace(-m - 1);
    for (int i = 1; i <= m; i++)
        yi[i].emplace(0), yi[i].emplace(n + 1), yi[i].emplace(0), yi[i].emplace(-n - 1);
    for (int i = 0; i < k; i++)
    {
        int a = read<int>(), b = read<int>();
        xi[a].emplace(b);
        yi[b].emplace(a);
        xd[a].emplace(-b);
        yd[b].emplace(-a);
    }
    init();
    ll cur = solve();
    if (cur == 1LL * n * m - k)
        puts("Yes");
    else
    {
        init();
        dic = 1;
        cur = solve();
        if (cur == 1LL * n * m - k)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}