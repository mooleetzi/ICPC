#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;

LL n,m,p;

LL quick_mod(LL a, LL b)
{
    LL ans = 1;
    a %= p;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % p;
            b--;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

LL C(LL n, LL m)
{
    if(m > n) return 0;
    LL ans = 1;
    for(int i=1; i<=m; i++)
    {
        LL a = (n + i - m) % p;
        LL b = i % p;
        ans = ans * (a * quick_mod(b, p-2) % p) % p;
    }
    return ans;
}

LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld%lld%lld", &n, &m, &p);
        printf("%lld\n", Lucas(n,m));
    }
    return 0;
}
