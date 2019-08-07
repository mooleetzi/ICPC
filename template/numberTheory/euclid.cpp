/*
    扩展欧几里得求乘法逆元
 */
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b != 0)
    {
        exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else
    {
        x = 1, y = 0;
        return a;
    }
}
ll inv(ll a)
{
    ll x, y;
    ll d = exgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

/*
    求ax+by=c的最小整数解
 */
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}
ll d = exgcd(a, b, x, y);
ll r = c / d; //c为同余方程余数或者不定方程右边常数
ll xa *= r;   //最终解
ll ya *= r;   //最终解
ll ta = b / d;
ll tb = a / d;
xa = (xa % ta + ta) % ta; //最小非负整数解
ya = (ya % tb + tb) % tb; //最小非负整数解