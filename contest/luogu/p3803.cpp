/*
    fft
    多项式乘法
    luogup3903
*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
#define comp std::complex<double>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
const int maxn = (int)(1e6 + 10) << 2;
const double PI = acos(-1);
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
int n, m, lim, r[maxn];
comp a[maxn], b[maxn];
void fft(comp *a, int n, int type)
{
    for (int i = 0; i < n; i++)
        if (i < r[i])
            swap(a[i], a[r[i]]);
    for (int i = 1; i < lim; i <<= 1)
    {
        comp x(cos(PI / i), type * sin(PI / i));
        for (int j = 0; j < lim; j += (i << 1))
        {
            comp y(1, 0);
            for (int k = 0; k < i; k++, y *= x)
            {
                comp p = a[j + k], q = y * a[j + k + i];
                a[j + k] = p + q;
                a[j + k + i] = p - q;
            }
        }
    }
}
int main()
{
    n = read<int>(), m = read<int>();
    for (int i = 0; i <= n; i++)
        a[i] = read<int>();
    for (int i = 0; i <= m; i++)
        b[i] = read<int>();

    int l = 0;
    for (lim = 1; lim <= n + m; lim <<= 1)
        ++l;
    for (int i = 0; i < lim; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1)); //获取对应位置，优化

    fft(a, lim, 1), fft(b, lim, 1);
    for (int i = 0; i <= lim; i++)
        a[i] *= b[i];
    fft(a, lim, -1);

    for (int i = 0; i <= n + m; i++)
        write((int)(0.5 + a[i].real() / lim)), putchar(' ');
    return 0;
}