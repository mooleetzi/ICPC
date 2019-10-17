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
/*
    大数素因子分解
*/
long long Pollard_rho(long long x, long long c)
{
    long long i = 1, k = 2;
    long long x0 = rand() % x;
    long long y = x0;
    while (1)
    {
        i++;
        x0 = (mult_mod(x0, x0, x) + c) % x;
        long long d = gcd(y - x0, x);
        if (d != 1 && d != x)
            return d;
        if (y == x0)
            return x;
        if (i == k)
        {
            y = x0;
            k += k;
        }
    }
}
//对n进行素因子分解
void findfac(long long n)
{
    if (Miller_Rabin(n)) //素数
    {
        factor[tol++] = n;
        return;
    }
    long long p = n;
    while (p >= n)
        p = Pollard_rho(p, rand() % (n - 1) + 1);
    findfac(p);
    findfac(n / p);
}