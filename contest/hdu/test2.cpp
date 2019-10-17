#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 45000
typedef long long ll;
const int M = 1e6 + 10;
ll f0, f1, a, b;
ll N, P;
ll prime[maxn];
ll fac[maxn];
char s[M];
inline ll read()
{
    long long X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch))
    {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch))
        X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return w ? -X : X;
}
inline void print(ll x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
void Prime()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i < maxn; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] < maxn / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}
ll factor[130][2];
int fatcnt;
int get_factors(ll n)
{
    fatcnt = 0;
    ll tmp = n;
    for (int i = 1; prime[i] <= tmp / prime[i]; i++)
    {
        factor[fatcnt][1] = 0;
        if (tmp % prime[i] == 0)
        {
            factor[fatcnt][0] = prime[i];
            while (tmp % prime[i] == 0)
            {
                tmp /= prime[i];
                factor[fatcnt][1]++;
            }
            fatcnt++;
        }
    }
    if (tmp != 1)
    {
        factor[fatcnt][0] = tmp;
        factor[fatcnt][1] = 1;
        fatcnt++;
    }
    return fatcnt;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
struct Matrix
{
    ll m[2][2];
} E, D;
Matrix Multi(Matrix A, Matrix B, ll mod)
{
    Matrix ans;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans.m[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                ans.m[i][j] += (A.m[i][k] * B.m[k][j]) % mod;
                if (ans.m[i][j] >= mod)
                {
                    ans.m[i][j] -= mod;
                }
            }
        }
    }
    return ans;
}
void init()
{
    memset(E.m, 0, sizeof(E.m));
    memset(D.m, 0, sizeof(D.m));
    D.m[0][0] = a;
    D.m[0][1] = b;
    D.m[1][0] = 1;
    for (int i = 0; i < 2; i++)
    {
        E.m[i][i] = 1;
    }
    Prime();
}
Matrix Pow(Matrix A, ll e, ll mod)
{
    Matrix ans = E;
    while (e)
    {
        if (e & 1)
        {
            ans = Multi(ans, A, mod);
        }
        A = Multi(A, A, mod);
        e >>= 1;
    }
    return ans;
}
ll Pow(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
ll get_fib(ll n, ll mod)
{
    if (mod == 1)
        return 0;
    if (n == 0)
        return f0 % mod;
    Matrix ans = Pow(D, n - 1, mod);
    return (ans.m[0][0] * f1 % mod + ans.m[0][1] * f0 % mod) % mod;
}
ll find_loop(ll n)
{
    get_factors(n);
    ll ans = 1;
    for (int i = 0; i < fatcnt; i++)
    {
        ll record = (factor[i][0] + 1) * (factor[i][0] - 1);
        for (int j = 1; j < factor[i][1]; j++)
            record *= factor[i][0];
        //printf("record:");print(record);puts("");
        if (record)
            ans = ans * record;
    }
    //printf("ans:");print(ans);puts("");
    return ans;
}
int main()
{
    f0 = read(); //print(f0);puts("");
    f1 = read(); //print(f1);puts("");
    a = read();  //print(a);puts("");
    b = read();  //print(b);puts("");
    init();
    // scanf("%s", s);
    P = read();
    ll mod2 = find_loop(P);
    cout << mod2 << "\n";
    // //printf("mod2:");print(mod2);puts("");
    // int len = strlen(s);
    // for (int i = 0; i < len; ++i)
    //     N = (N * 10 + (s[i] - '0')) % mod2;
    // N = get_fib(N, P);
    // print(N);
    // puts("");
    return 0;
}
