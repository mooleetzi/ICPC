#include <bits/stdc++.h>
#define ll long long
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef pair<int, int> P;
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
    void print()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cout << t[i][j] << " ";
            cout << "\n";
        }
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
ll solve(ll n, ll a, ll b, ll k)
{
    ll res = 0;
    for (ll i = 1; i <= n; i++)
        res = (res + qpow(mul(a, i) + b, k)) % mod;
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("1_1.out", "w", stdout);
#endif
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, k, n;
        cin >> n >> a >> b >> k;
        cout << solve(n, a, b, k) << "\n";
    }
    return 0;
}