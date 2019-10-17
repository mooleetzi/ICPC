/*
    O(1)快速乘
*/
inline ll mul(ll a, ll b, ll mod)
{
    return (a * b - (ll)((long double)a / mod * b) * mod + mod) % mod;
}
