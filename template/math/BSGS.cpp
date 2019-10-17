/*
    大步小步算法，离散对数取模
    在O(sqrt(p))复杂度在已知求得a^x=b(mod p)中的x值
 */
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
inline ll inv(ll a)
{
    return qpow(a, mod - 2);
}
ll BSGS(ll a, ll b)
{
    ll m = (ll)sqrt(mod + 0.5);
    map<ll, ll> x;
    x[1] = 0;
    ll ans = 1;
    for (int i = 1; i <= m; i++)
    {
        ans = ans * a % mod;
        if (!x.count(ans))
            x[ans] = i;
    }
    ll pm = inv(qpow(a, m));
    for (int i = 0; i < m; i++)
    {
        if (x.count(b))
            return i * m + x[b];
        b = b * pm % mod;
    }
    return -1;
}