
/*
    拉格朗日插值
*/
#include <bits/stdc++.h>
using namespace std;
double lagrange(const vector<double> &x, const vector<double> &y, double xx)
{
    double ans = 0;
    int sz = x.size();
    for (int i = 0; i < sz; i++)
    {
        double t0 = 1, t1 = 1;
        for (int j = 0; j < size_t; j++)
            if (i != j)
                t0 *= (x[i] - x[j]), t1 *= (xx - x[j]);
        ans += t1 / t0 * y[i];
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<double> xx, yy;
    for (int i = 0; i < n; i++)
    {
        double x0, y0;
        cin >> x0 >> y0;
        xx.push_back(x0);
        yy.push_back(y0);
    }
    double x;
    cin >> x;
    cout << lagrange(xx, yy, x);
    return 0;
}
/*
    自然数幂和
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 5e4 + 10;

int t;
ll n, k;

ll inv[N];
ll a[N];           //前 k+2 项自然数 k 次幂和   也就是yi
ll pre[N], suf[N]; //前缀积 后缀积
ll fac[N];

ll qpow(ll x, ll y)
{
    ll ans = 1;
    while (y)
    {
        if (y & 1)
            ans = ans * x % mod;
        x = x * x % mod, y >>= 1;
    }
    return ans;
}

ll solve(ll x)
{                   //前 x 项和
    if (x <= k + 2) //直接返回
        return a[x];
    x %= mod;
    ll ans = 0;
    pre[0] = suf[k + 3] = 1; //边界
    for (ll i = 1; i <= k + 2; i++)
    { //(x-i) 前缀积
        pre[i] = pre[i - 1] * (x - i) % mod;
    }
    for (ll i = k + 2; i >= 1; i--)
    { //(x-i) 后缀积
        suf[i] = suf[i + 1] * (x - i) % mod;
    }
    for (ll i = 1; i <= k + 2; i++)
    {
        ll f = fac[i - 1] * fac[k + 2 - i] % mod;
        f = (k + 2 - i) & 1 ? -f : f; //判断正负
        (ans += a[i] * f % mod * pre[i - 1] % mod * suf[i + 1]) %= mod;
    }
    ans += ans < 0 ? mod : 0;
    return ans;
}
void init()
{
    for (ll i = 1; i < N; i++)
        inv[i] = qpow(i, mod - 2);
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * inv[i] % mod;
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (ll i = 1; i <= k + 2; i++)
            a[i] = (a[i - 1] + qpow(i, k)) % mod;
        cout << solve(n) << "\n";
    }
    return 0;
}