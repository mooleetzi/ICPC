/*
    可以从题意得知满足答案满足一个递推关系
    r[n]=r[n-1]+f(n),f(n)=(1,n)+(2,n)+...+(n-1,n)
    对于f(n)如何求解呢，假设(x,n)=i,则有关系(x/i,n/i)=1
    x<n,则x/i<n/i，即我们需要求小于n/i的数中与n/i互素的数个数，即phi(n/i)
    那么这一组数对f(n)的贡献就为phi(n/i)*i
    循环暴力gcd所有可能情况即可
    循环推出r数组，o(1)查询
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
const int maxn = 4e6 + 10;
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
int phi[maxn];
ull r[maxn], a[maxn];
void init()
{
    for (int i = 1; i < maxn; i++)
        phi[i] = i;
    for (int i = 2; i < maxn; i++)
    {
        if (phi[i] == i)
            for (int j = i; j < maxn; j += i)
                phi[j] = phi[j] / i * (i - 1);
    }
    for (int i = 1; i < maxn; i++)
        for (int j = 2 * i; j < maxn; j += i)
            a[j] += (ull)phi[j / i] * i;
    for (int i = 2; i < maxn; i++)
        r[i] = r[i - 1] + a[i];
}
inline ull solve(int n)
{
    return r[n];
}
int main(int argc, char const *argv[])
{
    init();
    while (read(n))
    {
        write(solve(n));
        putchar('\n');
    }
    return 0;
}
