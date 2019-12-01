#include <bits/stdc++.h>
#define ll long long
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const ll mod = 1e9 + 9;
int n, m, k;
struct mat
{
    int r, c;
    ll t[25][25];
    mat() { mat(21, 21); }
    mat(int rr, int cc) : r(rr), c(cc) { memset(t, 0, sizeof t); }
    void toEye()
    {
        for (int i = 0; i < r; ++i)
            t[i][i] = 1;
    }
    mat operator*(const mat &b)
    {
        mat res(r, b.c);
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < b.c; ++j)
            {
                res.t[i][j] = 0;
                for (int k = 0; k < c; ++k)
                    res.t[i][j] = (res.t[i][j] + t[i][k] * b.t[k][j]) % mod;
            }
        return res;
    }
};
mat qpow(mat base, ll n)
{
    mat res(base.r, base.r);
    res.toEye();
    for (; n; n >>= 1)
    {
        if (n & 1)
            res = res * base;
        base = base * base;
    }
    return res;
}
ll qpow(ll base, ll n)
{
    base %= mod;
    ll res = 1;
    for (; n; n >>= 1)
    {
        if (n & 1)
            res = res * base % mod;
        base = base * base % mod;
    }
    return res;
}
ll C[25][25];
void init()
{
    for (int i = 0; i < 21; ++i)
    {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (int i = 1; i < 21; ++i)
        for (int j = 1; j < 21; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
}
inline ll mul(ll a, ll b)
{
    return (a * b - (ll)((long double)a / mod * b) * mod + mod) % mod;
}
int main(int argc, char const *argv[])
{
    fastIO;
    int t;
    cin >> t;
    init();
    while (t--)
    {
        ll a, b, k, n;
        cin >> n >> a >> b >> k;
        mat res(k + 2, 1);
        for (int i = 0; i < k + 1; ++i)
            res.t[i][0] = 1;
        res.t[k + 1][0] = qpow(a + b, k);
        mat trans(k + 2, k + 2);
        for (int i = 0; i < k + 1; ++i)
        {
            for (int j = i; j < k + 1; ++j)
                trans.t[i][j] = C[k - i][j - i];
            trans.t[i][k + 1] = 0;
        }
        for (int i = 0; i < k + 1; ++i)
            trans.t[k + 1][i] = mul(mul(C[k][i], qpow(a, k - i)), qpow(a + b, i));
        trans.t[k + 1][k + 1] = 1;
        mat tmp = qpow(trans, n - 1);
        res = tmp * res;
        cout << res.t[k + 1][0] << "\n";
    }
    return 0;
}