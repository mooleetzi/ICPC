/*
    威佐夫博弈+循环判断第一个开局
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
inline int judge(int n, int m)
{
    static double p = (sqrt(5.0) + 1) / 2;
    int x = abs(n - m);
    if ((int)(x * p) == min(n, m))
        return 0;
    return 1;
}
set<P> s;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), m = read<int>();
    do
    {
        s.clear();
        if (judge(n, m))
        {
            puts("1");
            int t1 = n, t2 = m, k = min(t1, t2);
            for (int i = 1; i < k; i++)
                if (!judge(t1 - i, t2 - i))
                    printf("%d %d\n", t1 - i, t2 - i);
            for (int i = 1; i < n; i++)
                if (!judge(t1 - i, t2))
                    s.emplace(min(t1 - i, t2), max(t1 - i, t2));
            for (int i = 1; i < m; i++)
                if (!judge(t2 - i, t1))
                    s.emplace(min(t2 - i, t1), max(t2 - i, t1));
            for (auto x : s)
                printf("%d %d\n", x.first, x.second);
        }
        else
            puts("0");
        n = read<int>(), m = read<int>();
    } while (n != 0 && m != 0);
    return 0;
}