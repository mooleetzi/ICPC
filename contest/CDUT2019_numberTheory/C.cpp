//唯一分解定理
//我们知道对于一个正整数n可以分解为n=(p0^a0)*(p1^a1)*...,p为素因子
//这时正整数n的约数个数就是(1+a0)*(1+a1)*(1+a2)*(1+a3)...
//对于此题，我们可以先用欧拉筛筛出前sqrt（max(a))的数，然后求出约数个数，
//约数个数/2即为全部的整数对（i，j)满足i*j=a
//要使min(i,j)>=b
//我们只需要将前b个自然数中的约数个数剪掉即可
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const int maxn = 1e6 + 10;
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
int cnt = 0;
void init() //欧拉筛
{
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] * i < maxn; j++)
        {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    read(t);
    int tot = 0;
    while (t--)
    {
        ll a, b;
        read(a);
        read(b);
        int ans = 0;
        if (b * b <= a)
        {
            ll tmp = a;
            ans = 1;
            for (int i = 0; i < cnt && prime[i] <= sqrt(tmp); i++)
            {
                if (tmp % prime[i] == 0)
                {
                    int cur = 0;
                    while (tmp % prime[i] == 0)
                    {
                        ++cur;
                        tmp /= prime[i];
                    }
                    ans *= (1 + cur);
                }
            }
            if (tmp > 1)
                ans <<= 1;
            ans >>= 1;
            for (int i = 1; i < b; i++)
                if (a % i == 0)
                    --ans;
        }
        printf("Case %d: %d\n", ++tot, ans);
    }
    return 0;
}
