/*
    多项式乘法
    luogup3903
*/

#include <complex>
#define comp std::complex<double>
using namespace std;

const int maxn = (1e6 + 10) * 4;
const double PI = acos(-1);

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
    n = read(), m = read();
    for (int i = 0; i <= n; i++)
        a[i] = read();
    for (int i = 0; i <= m; i++)
        b[i] = read();

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
        printf("%d ", (int)(0.5 + a[i].real() / lim));
    return 0;
}

/*
    fft
    高精度乘法
    luogup1919
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    char t1[n + 2], t2[n + 2];
    cin >> t1 >> t2;
    for (int i = 0; i < n; i++)
        a[n - 1 - i] = t1[i] - '0';
    for (int i = 0; i < n; i++)
        b[n - 1 - i] = t2[i] - '0';
    int l = 0;
    for (lim = 1; lim <= 2 * n; lim <<= 1)
        ++l;
    for (int i = 0; i <= lim; i++)
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1)); //获取对应位置，优化

    fft(a, lim, 1), fft(b, lim, 1);
    for (int i = 0; i <= lim; i++)
        a[i] *= b[i];
    fft(a, lim, -1);
    int f = 0;
    int ans[lim + 1];
    memset(ans, 0, sizeof ans);
    for (int i = 0; i <= lim; i++)
    {
        int tmp = (int)((a[i].real() + 0.5) / lim);
        ans[i] += tmp;
        if (ans[i] >= 10)
        {
            ans[i + 1] += ans[i] / 10, ans[i] %= 10;
            lim += i == lim;
        }
    }
    while (!ans[lim] && lim > 0)
        --lim;
    ++lim;
    while (lim--)
        cout << ans[lim];
    return 0;
}