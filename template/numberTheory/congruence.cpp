#include <vector>
using namespace std;
/*
秦九韶-大衍求一术求解ax=1(mod p),(a,p)=1
 */
int dyqy(int a, int p)
{
    if (__gcd(a, p) != 1)
        return -1; //不能用大衍求一术
    vector<int> k, r, q;
    k.emplace_back(0), k.emplace_back(1); //k0=0,k1=1
    r.emplace_back(p), r.emplace_back(a); //r0=p,r1=a
    q.emplace_back(-1), q.emplace_back(-1);
    int i = 0;
    while (1)
    {
        int ra = r[i], rb = r[i + 1];
        int qtmp = ra / rb;
        int rtmp = ra % rb;
        q.emplace_back(qtmp);
        r.emplace_back(rtmp);
        ++i;
        if (rtmp == 1)
            break;
    }
    int sz = r.size();
    for (int i = 2; i < sz; i++)
    {
        int ktmp = k[i - 2] - k[i - 1] * q[i];
        k.emplace_back(ktmp);
    }
    return k.back();
}

/*
    普通孙子定理/中国剩余定理，求解模数互素的同余方程组
    m除数，r余数
 */
ll exgcd(ll a, ll b, ll &x, ll &y) //求逆元
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

ll crt()
{
    ll d, x, y, ret = 0;
    ll temp;
    ll M = 1;
    for (int i = 0; i < n; i++)
        M *= m[i]; //m是除数
    for (int i = 0; i < n; i++)
    {
        temp = M / m[i];
        d = exgcd(m[i], temp, x, y);       //求temp在模mi意义下的逆元
        ret = (ret + y * temp * r[i]) % M; //b是余数
    }
    return (ret + M) % M;
}

/*
    扩展中国剩余定理
    可求解m不互质的同余方程组
    m除数，r余数
 */

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