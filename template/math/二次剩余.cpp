/*
    二次剩余存在条件
        a^[(p-1)/2]==p-1 (mod p) ->不存在
*/
struct num
{
    ll x, y;
};
ll w;
num mul(num a, num b, ll p)
{
    num ans = {0, 0};
    ans.x = ((a.x * b.x % p + a.y * b.y % p * w % p) % p + p) % p;
    ans.y = ((a.x * b.y % p + a.y * b.x % p) % p + p) % p;
    return ans;
}

ll powwR(ll a, ll b, ll p)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = 1ll * ans % p * a % p;
        a = a % p * a % p;
        b >>= 1;
    }
    return ans % p;
}
ll powwi(num a, ll b, ll p)
{
    num ans = {1, 0};
    while (b)
    {
        if (b & 1)
            ans = mul(ans, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ans.x % p;
}

ll solve(ll n, ll p)
{
    n %= p;
    if (p == 2)
        return n;
    if (powwR(n, (p - 1) / 2, p) == p - 1)
        return -1; //不存在
    ll a;
    while (1)
    {
        a = rand() % p;
        w = ((a * a % p - n) % p + p) % p;
        if (powwR(w, (p - 1) / 2, p) == p - 1)
            break;
    }
    num x = {a, 1};
    return powwi(x, (p + 1) / 2, p);
}