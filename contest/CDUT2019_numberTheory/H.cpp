/* 
唯一分解定理
lcm(a,b)=n,则
n=p1^r1*p2^r2...pm^rm
a=p1^a1*p2^a2...pm^am
b=p1^b1*p2^b2...pm^bm
对于每一个ri都有ai+bi=ri，且ai，bi必须有一个为ri
所以一个ri对应有2(ri+1),(从0开始)种贡献，不过当ai=bi=ri时算了两次，应减去
因此最终每一个素因子对答案的贡献就是2*(ri+1)-1=2*ri+1
根据分步原理ans=PI(2*ri+1)
计算完毕后，我们可以直到，对于所有的a，b我们计算了a>=b和a<b的情况（除了最后a=b=n),即求出的是答案的二倍
因此最后答案是ans=ans/2+1
*/

#pragma optmize(3)
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
int prime[maxn / 10];
bool vis[maxn];
int pcnt = 0;
void init()
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[pcnt++] = i;
        for (int j = 0; j < pcnt && i * prime[j] < maxn; j++)
        {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
inline ll lcm(ll a, ll b)
{
    ll g = __gcd(a, b);
    return a / g * b;
}
ll solve(ll c)
{
    ll ans = 1;
    for (int i = 0; i < pcnt && prime[i] * prime[i] <= c; i++)
    {
        int cur = 0;
        while (c % prime[i] == 0)
        {
            c /= prime[i];
            ++cur;
        }
        if (cur)
            ans *= (2 * cur + 1);
    }
    if (c > 1)
        ans *= 3;
    return ans / 2 + 1;
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    read(t);
    int tot = 0;
    while (t--)
    {
        ll n;
        read(n);
        printf("Case %d: %lld\n", ++tot, solve(n));
    }
    return 0;
}
