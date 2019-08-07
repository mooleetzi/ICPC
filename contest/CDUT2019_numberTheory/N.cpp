/*
    n!末尾0的个数只与5这个素因子有关
    有公式f(n,p)=f(n/p,p)+n/p,求n!内因子p的个数
    打表可知出现n个0的情况在4*n+1以后，由此可以将区间确定在一个小范围
 */
#pragma optimize(3)
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k, mod;
const int maxn = 1e5 + 10;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
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
ull f(ull n, int p)
{
    if (n == 0)
        return 0;
    return f(n / p, p) + n / p;
}
ull solve(ull n, int p)
{
    for (ull i = 4 * n + 1;; i++)
    {
        if (f(i, p) == n)
            return i;
        if (f(i, p) > n)
            return 0;
    }
}
int main(int argc, char const *argv[])
{
    int t;
    read(t);
    int tot = 0;
    while (t--)
    {
        ull a;
        read(a);
        ull ans = solve(a, 5);
        if (!ans)
            printf("Case %d: impossible\n", ++tot);
        else
            printf("Case %d: %llu\n", ++tot, ans);
    }
    return 0;
}
