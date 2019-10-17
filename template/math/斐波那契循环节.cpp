/*
    对于一个正整数n，求Fib数列模n的循环节方法如下:

        1) n素因子分解为n=(p1^a1)(p2^a2)...
        2) 分别计算Fib数列模p^m的循环节，假设长度为x1,x2,x3..
        3) Fib循环节长度L=lcm(x1,x2,x3,..)
    Fib模p^m的循环节求法：
        令G(p)为Fib模p的最小循环节，则G(p^m)=G(p)*p^(m-1)

    G(p)求法
        如果5是模p的二次剩余，那么循环节长度为p-1的因子，否则为2(p+1)因子
        那么我们可以先求出所有的因子，然后用矩阵快速幂来一个一个判断
        小于等于5的素数：G(2)=3,G(3)=8,G(5)=20

    广义斐波那契循环节
        def:对于F(n)=aF(n-1)+bF(n-2)的式子，记作广义斐波那契数列，模p循环节求法如下
        
        1)记c=a^2+4b
        2)如果c是p的二次剩余，则最小循环节为p-1的因子
        3)如果c不是p的二次剩余，则最小循环节是(p-1)*(p+1)的因子

*/
//hdu3977 Fibonacci模n循环节
int pri[maxn], num[maxn], fac[maxn];
int ptot, ftot;
int prime[maxn], vis[maxn], pcnt;
struct mat
{
    ll f[2][2];
};
mat I = {1, 0, 0, 1}, A = {1, 1, 1, 0};
mat mul(const mat &a, const mat &b, ll mod)
{
    mat res;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            res.f[i][j] = 0;
            for (int k = 0; k < 2; k++)
                res.f[i][j] = (res.f[i][j] + a.f[i][k] * b.f[k][j] % mod) % mod;
        }
    return res;
}
mat qpow(mat a, ll n, ll mod)
{
    mat res = I;
    while (n)
    {
        if (n & 1)
            res = mul(res, a, mod);
        a = mul(a, a, mod);
        n >>= 1;
    }
    return res;
}
void init()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[pcnt++] = i;
        for (int j = 0; j < pcnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
void getFac(ll n)
{
    ftot = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            fac[ftot++] = i;
            if (i * i != n)
                fac[ftot++] = n / i;
        }
    }
}
void getPri(ll n)
{
    ptot = 0;
    for (int i = 0; i < pcnt && (ll)prime[i] * prime[i] <= n; i++)
    {
        if (n % prime[i] == 0)
        {
            int c = 0;
            while (n % prime[i] == 0)
            {
                ++c;
                n /= prime[i];
            }
            pri[ptot] = prime[i];
            num[ptot++] = c;
        }
    }
    if (n > 1)
    {
        pri[ptot] = n;
        num[ptot++] = 1;
    }
}
ll qpow(ll a, ll n, ll p)
{
    a %= p;
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return res;
}
LL legendre(LL a, LL p)
{
    if (qpow(a, (p - 1) >> 1, p) == 1)
        return 1;
    else
        return -1;
}
ll solve(ll n)
{
    getPri(n);
    ll res = 1;
    for (int i = 0; i < ptot; i++)
    {
        ll tmp = 1;
        if (pri[i] == 2)
            tmp = 3;
        else if (pri[i] == 3)
            tmp = 8;
        else if (pri[i] == 5)
            tmp = 20;
        else
        {
            if (legendre(5, pri[i]) == 1)
                getFac(pri[i] - 1);
            else
                getFac(2 * (pri[i] + 1));
            sort(fac, fac + ftot); //最小循环节，必须排序
            for (int j = 0; j < ftot; j++)
            {
                mat cur = qpow(A, fac[j] - 1, pri[i]);
                ll x = (cur.f[0][0] % pri[i] + cur.f[0][1] % pri[i]) % pri[i];
                ll y = (cur.f[1][0] % pri[i] + cur.f[1][1] % pri[i]) % pri[i];
                if (x == 1 && y == 0)
                {
                    tmp = fac[j];
                    break;
                }
            }
        }
        for (int k = 1; k < num[i]; k++)
            tmp *= pri[i];
        res = res / __gcd(res, tmp) * tmp;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    init();
    int t = read<int>();
    for (int cas = 1; cas <= t; ++cas)
    {
        n = read<int>();
        printf("Case #%d: %lld\n", cas, solve(n));
    }
    return 0;
}

/*
    广义斐波那契循环节
    已知递推x0,x1,a,b(1~1e9)
    求xn=a*x(n-1)+b*x(n-2)(mod m)
    1<=n<=1e(1e6),1<=m<=2e9
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2;
LL mod = 1000000007;
int cnt, ct;
LL pri[100005];
LL num[100005];
struct Matrix
{
    LL m[N][N];
};
Matrix A;
Matrix I = {1, 0, 0, 1};
char str[1000005];
map<int, int> y;
int flag = 0;
Matrix multi(Matrix a, Matrix b)
{
    Matrix c;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            c.m[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j] % mod) % mod;
            }
        }
    }
    return c;
}
Matrix power(Matrix A, LL n)
{
    Matrix ans = I, p = A;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = multi(ans, p);
            n--;
        }
        n >>= 1;
        p = multi(p, p);
    }
    return ans;
}
LL quick_mod(LL a, LL b, LL MOD)
{
    LL ans = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a % MOD;
            b--;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}
LL quick_mul(LL a, LL b, LL MOD)
{
    LL ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = ans + a;
            if (ans > MOD)
            {
                ans %= MOD;
                flag = 1;
            }
        }
        a = a + a;
        if (a > MOD)
        {
            a %= MOD;
            flag = 1;
        }
        b = b / 2;
    }
    return ans;
}
LL Legendre(LL a, LL p, LL MOD)
{
    LL t = quick_mod(a, (p - 1) >> 1, MOD);
    if (t == 1)
        return 1;
    return -1;
}
void yinzi(LL x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
            {
                y[i]++;
                x = x / i;
            }
        }
    }
    if (x > 1)
    {
        y[x]++;
    }
}
LL lcm(LL a, LL b)
{
    return a / __gcd(a, b) * b;
}
LL get_len(LL a, LL b, LL mod)
{
    yinzi(mod);
    for (map<int, int>::iterator i = y.begin(); i != y.end(); i++)
    {
        pri[cnt] = i->first;
        num[cnt] = i->second;
        cnt++;
    }
    LL ans = 1;
    LL c = a * a + 4 * b;
    for (int i = 0; i < cnt; i++)
    {
        LL p = 1;
        if (pri[i] == 2)
        {
            p *= 3;
            for (int j = 0; j <= num[i]; j++)
                p *= pri[i];
        }
        else if (c % pri[i] == 0)
        {
            p *= pri[i] * (pri[i] - 1);
            for (int j = 1; j < num[i]; j++)
                p *= pri[i];
        }
        else if (Legendre(c, pri[i], pri[i]) == 1)
        {
            p *= (pri[i] - 1);
            for (int j = 1; j < num[i]; j++)
                p *= pri[i];
        }
        else
        {
            p *= (pri[i] - 1) * (pri[i] + 1);
            for (int j = 1; j < num[i]; j++)
                p *= pri[i];
        }
        ans = lcm(ans, p);
    }
    return ans;
}
int main()
{
    LL a, b, c, d;
    cin >> c >> d >> a >> b;
    cin >> str >> mod;
    LL p = get_len(a, b, mod);
    LL n = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        n = quick_mul(n, 10, p) + str[i] - '0';
    }
    if (flag)
        n += p;
    A.m[0][0] = a;
    A.m[0][1] = b;
    A.m[1][0] = 1;
    A.m[1][1] = 0;
    Matrix T = power(A, n - 1);
    long long ans = (T.m[0][0] * d % mod + T.m[0][1] * c % mod) % mod;
    printf("%lld\n", ans);
    return 0;
}