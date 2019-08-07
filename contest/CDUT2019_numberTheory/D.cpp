//一个数所有因子和为(1+p1+p1^2+...+p1^e1)*(1+p2+p2^2+...p2^e2)*...()
//打表发现因子和为奇数的数是平方数或2倍平方数
//减去即可
//注意sqrt返回值为浮点数，需要转换为ll，不然double/float转ll会丢失精度，就wa
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const ll maxn = 1e6;
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
ll prime[maxn];
int vis[maxn];
int pcnt = 0;
void init() //欧拉筛
{
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
ll cal(int p, int n)
{
    ll sum = 1;
    ll t = 1;
    for (int i = 0; i < n; i++)
    {
        t *= p;
        sum += t;
    }
    // cout << "sum"
    //      << " :" << p << " " << n << " " << sum << "\n";
    return sum;
}
int getFacSum(int x)
{
    ll sum = 1;
    for (int i = 0; i < pcnt && prime[i] * prime[i] <= x; i++)
    {
        int p = prime[i];
        int cur = 0;
        while (x % p == 0)
        {
            ++cur;
            x /= p;
        }
        ll t = cal(p, cur);
        sum *= t;
    }
    if (x > 1)
        sum *= cal(x, 1);
    return sum;
}
void dabiao()
{
    for (int i = 1; i <= 100; i++)
        // getFacSum(i);
        if (getFacSum(i) & 1)
            cout << i << ": " << getFacSum(i) << "\n";
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    // dabiao();
    read(t);
    int tot = 0;
    while (t--)
    {
        ll x;
        read(x);
        ll ans = x;
        ans = ans - (ll)sqrt(x) - (ll)sqrt(x / 2);
        printf("Case %d: %lld\n", ++tot, ans);
    }
    return 0;
}
