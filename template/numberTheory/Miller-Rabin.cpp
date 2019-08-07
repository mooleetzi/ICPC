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