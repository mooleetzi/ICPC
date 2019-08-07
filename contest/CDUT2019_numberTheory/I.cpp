/*
h(n)≈ln(n)+C+1/(2*n) 
C为欧拉常数=0.57721566490153286060651209
仅在n比较大时适用

也阔以打表分50个记录一个
 */
// #pragma optmize(3)
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const int maxn = 1e8 + 1;
const double r = 0.57721566490153286060651209;
const int mod = 998244353;
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
double a[10010];
void init()
{
    a[0] = 0;
    for (int i = 1; i <= 10000; i++)
        a[i] = a[i - 1] + 1.0 / i;
}
double h(int n)
{
    if (n <= 10000)
        return a[n];
    return log(n) + r + 1 / (2.0 * n);
}
double ans[2000100];
void dabiao()
{
    double tmp = 1;
    for (int i = 2; i < maxn; i++)
    {
        tmp += 1.0 / i;
        if (i % 50 == 0)
            ans[i / 50] = tmp;
    }
}
double solve(int n)
{
    int pre = n / 50;
    double a = ans[pre];
    pre *= 50;
    ++pre;
    for (; pre <= n; pre++)
        a += (ld)1.0 / pre;
    return a;
}
int main(int argc, char const *argv[])
{
    // init();
    dabiao();
    int t;
    read(t);
    int tot = 0;
    while (t--)
    {
        int n;
        read(n);
        printf("Case %d: %.10lf\n", ++tot, solve(n));
    }
    return 0;
}
