/*
    卡精度真的恶心，记得最后加一个eps
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
const int maxn = 1e8 + 1e5;
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
bool vis[maxn];
int prime[maxn / 10], pcnt;
void init()
{
    for (int i = 2; i <= maxn; i++)
    {
        if (!vis[i])
            prime[pcnt++] = i;
        for (int j = 0; j < pcnt && i * prime[j] <= maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
inline int isprime(int x)
{
    return !vis[x];
}
inline int f(int x)
{
    return x * x + x + 41;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    init();
    while (cin >> a >> b)
    {
        ld mu = b - a + 1;
        ld deno = 0;
        for (int i = a; i <= b; i++)
            deno += isprime(f(i));
        ld ans = deno / mu * 100;
        cout << fixed << setprecision(2) << ans + 1e-4 << "\n";
    }
    return 0;
}
