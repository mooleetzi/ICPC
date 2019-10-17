#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
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
int n, m;
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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
const int maxn = 15;
ll q, C[maxn], M[maxn], x, y;
ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll r = exgcd(b, a % b, x, y), tmp;
    tmp = x;
    x = y;
    y = tmp - (a / b) * y;
    return r;
}
ll inv(ll a, ll b)
{
    ll r = exgcd(a, b, x, y);
    while (x < 0)
        x += b;
    return x;
}
ll mp[60];
inline bool judge(ll x)
{
    for (int i = 0; i < 52; i++)
        if (mp[i] == x)
            return 1;
    return 0;
}
ll mul(ll A, ll B, ll mod)
{
    ll ans = 0;
    while (B > 0)
    {
        if (B & 1)
            ans = (ans + A % mod) % mod;
        A = (A + A) % mod;
        B >>= 1;
    }
    return ans;
}
ll lcm(ll A, ll B) //求最小公倍数
{
    ll xxx, yyy;
    ll g = exgcd(A, B, xxx, yyy);
    return (A / g * B);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll a = 1, b = 1, t = 0;
    while (a <= 1e18)
    {
        mp[t++] = a;
        ll tmp = b;
        b = a + b;
        a = tmp;
    }
    int q = read<int>();
    for (int i = 1; i <= q; i++)
        M[i] = read<ll>(), C[i] = read<ll>();
    bool flag = (M[1] > C[1]);
    ll M1 = M[1], ans = C[1];
    for (int i = 2; i <= q && flag; i++)
    {
        ll A = M1, B = M[i];
        ll g = exgcd(A, B, x, y);
        ll cd = (C[i] - ans % B + B) % B;
        if (cd % g || C[i] >= M[i])
        {
            flag = 0;
            break;
        }
        x = mul(x, cd / g, B);
        ans += x * M1;
        M1 = lcm(M1, B);
        ans = (ans % M1 + M1) % M1;
    }
    if (!flag || ans > 1e15 || ans <= 1)
    {
        printf("Tankernb!");
    }
    else
    {
        ll p = ans;
        if (judge(p))
            printf("Lbnb!");
        else
            printf("Zgxnb!");
    }
    return 0;
}