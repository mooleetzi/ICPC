//还有对于负数的处理
//对于整数，ans=(r1,r2,...rn)
//对于负数，先取相反数，然后如果ans为偶数，则一直/2直到不为偶数
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const ll maxn = 1LL << 31;
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
int solve(ll n)
{
    int ans = -1;
    for (ll i = 2; i * i <= n; i++)
    {
        int cur = 0;
        while (n % i == 0)
        {
            ++cur;
            n /= i;
        }
        if (cur)
        {
            if (ans != -1)
                ans = __gcd(ans, cur);
            else
                ans = cur;
        }
    }
    if (n > 1)
        ans = 1;
    return ans;
}
int main(int argc, char const *argv[])
{
    int t;
    read(t);
    int tot = 0;
    while (t--)
    {
        ll n;
        read(n);
        int f = 0;
        if (n < 0)
        {
            f = 1;
            n = -n;
        }
        int ans = solve(n);
        if (f)
        {
            while (ans % 2 == 0)
                ans /= 2;
        }
        printf("Case %d: %d\n", ++tot, ans);
    }
    return 0;
}
