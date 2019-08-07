/*
    扩展中国剩余定理板题
 */
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> m, r;
ll n;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll ret = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return ret;
}
ll excrt()
{
    ll M = m[0], R = r[0], x, y, d;
    for (int i = 1; i < n; i++)
    {
        d = exgcd(M, m[i], x, y);
        if ((R - r[i]) % d)
            return -1;
        x = (R - r[i]) / d * x % m[i];
        R -= M * x;
        M = M / d * m[i];
        R %= M;
    }
    return (R % M + M) % M;
}
int main(int argc, char const *argv[])
{
    while (~scanf("%lld", &n))
    {
        m.clear(), r.clear();
        for (int i = 0; i < n; i++)
        {
            ll mm, rr;
            scanf("%lld%lld", &mm, &rr);
            m.push_back(mm), r.push_back(rr);
        }
        printf("%lld", excrt());
        puts("");
    }
    return 0;
}
