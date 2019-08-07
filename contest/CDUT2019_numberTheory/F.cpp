//sbOj，mle给我报re
//素数筛
//处理到n/2即可
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const int maxn = 1e7 + 1000;
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
int pcnt, prime[maxn / 10];
short vis[maxn];
void init()
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[pcnt++] = i;
        for (int j = 0; j < pcnt && prime[j] * i < maxn; j++)
        {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int solve(int n)
{
    int ans = 0;
    for (int i = 0; i < pcnt && prime[i] <= n / 2; i++)
    {
        if (!vis[n - prime[i]])
            ++ans;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    scanf("%d", &t);
    int tot = 0;
    while (t--)
    {
        int n;
        // read(n);
        scanf("%d", &n);
        printf("Case %d: %d\n", ++tot, solve(n));
    }
    return 0;
}
