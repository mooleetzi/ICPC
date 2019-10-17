#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 1e5 + 10;
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

ll multiMod(ll a, ll b, ll mod) //快速积（和快速幂差不多）
{
    ll ans = 0, res = a;
    while (b)
    {
        if (b & 1)
            ans = (ans + res) % mod;
        res = (res + res) % mod;
        b >>= 1;
    }
    return ans;
}
ll powerMod(ll a, ll b, ll mod)
{
    ll ret = 1LL;
    a %= mod;
    while (b)
    {
        if (b & 1LL)
            ret = multiMod(ret, a, mod), --b;
        b >>= 1LL;
        a = multiMod(a, a, mod);
    }
    return ret;
}

//Miller-Rabin测试,测试n是否为素数
bool Miller_Rabin(ll n, int repeat)
{
    if (2LL == n || 3LL == n)
        return true;
    if (!(n & 1LL))
        return false;

    //将n分解为2^s*d
    ll d = n - 1LL;
    int s = 0;
    while (!(d & 1LL))
        ++s, d >>= 1LL;

    srand((unsigned)time(0));
    for (int i = 0; i < repeat; ++i)
    {                                //重复repeat次
        ll a = rand() % (n - 3) + 2; //取一个随机数,[2,n-1)
        ll x = powerMod(a, d, n);
        ll y = 0LL;
        for (int j = 0; j < s; ++j)
        {
            y = multiMod(x, x, n);
            if (1LL == y && 1LL != x && n - 1LL != x)
                return false;
            x = y;
        }
        if (1LL != y)
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n = read<ll>(), k = read<ll>();
    ll res;
    if (n == 2)
        res = 1;
    else if (k >= (n + 1) / 2 && Miller_Rabin(k + 1, 5))
        res = 1;
    else
        res = 2;
    write(res);
    return 0;
}
