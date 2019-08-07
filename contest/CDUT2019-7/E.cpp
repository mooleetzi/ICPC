#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define debug
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k, p;
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
int phi[maxn];
void init()
{
    for (int i = 1; i < maxn; i++)
        phi[i] = i;
    for (int i = 2; i < maxn; i++)
        if (phi[i] == i)
            for (int j = i; j < maxn; j += i)
                phi[j] = phi[j] * (i - 1) / i;
#ifdef debug
    for (int i = 1; i < 100; i++)
        cout << i << ": " << phi[i] << "\n";
#endif
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    read(t);
    while (t--)
    {
        read(m), read(n), read(p);
        ll ans = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                ll cur = phi[i * j] / (phi[i] * phi[j]);
                ans += cur;
            }
        cout << ans % p << "\n";
    }
    return 0;
}
