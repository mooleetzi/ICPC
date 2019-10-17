/*
    打表，适合i<=1e4的情况
 */
const int M = 10007;
const int MAXN = 1000;
int C[MAXN + 1][MAXN + 1];
void Initial()
{
    int i, j;
    for (i = 0; i <= MAXN; ++i)
    {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (i = 1; i <= MAXN; ++i)
    {
        for (j = 1; j <= MAXN; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
}
int Combination(int n, int m)
{
    return C[n][m];
}

const int M = 10007;
const int MAXN = 1000;
int C[MAXN + 1][MAXN + 1];
void Initial()
{
    int i, j;
    for (i = 0; i <= MAXN; ++i)
    {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (i = 1; i <= MAXN; ++i)
    {
        for (j = 1; j <= MAXN; ++j)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }
}
int Combination(int n, int m)
{
    return C[n][m];
}

/*
    乘法逆元求组合数,适合n,m比较小 O(n)复杂度
 */
ll fac[maxn];

ll inv[maxn];
ll mod = 1e5 + 7;
void init()
{
    ll f = 1;
    inv[0] = 1;
    inv[1] = 1;
    fac[0] = fac[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        f = (f * i) % mod;
        fac[i] = f;
    }
    for (int i = 2; i < maxn; i++)
        inv[i] = inv[mod % i] * (mod - mod / i) % mod; //O(n)求逆元

    for (int i = 2; i < maxn; i++)
        inv[i] = inv[i - 1] * inv[i] % mod; //扩展到i!的逆元
}
inline ll C(ll n, ll m, ll p)
{
    if (m > n)
        return 0;
    return fac[n] * inv[m] % p * inv[n - m] % p;
}
/* 加上lucas定理，适合n，m比较大，p是素数且较小 O(p)*/
inline LL lucas(LL n, LL m, LL p)
{
    ll res = 1;
    while (n | m)
    {
        res = res * C(n % p, m % p, p) % p;
        n /= p, m /= p;
    }
    return res;
}
/*扩展lucas定理 可解p非素数*/
ll quick_mod(ll a, ll b, ll m)
{
    ll ans = 1ll;
    while (b)
    {
        if (b & 1)
            ans = ans * a % m;
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (a % b == 0)
    {
        x = 0ll;
        y = 1ll;
        return b;
    }
    ll v, tx, ty;
    v = exgcd(b, a % b, tx, ty);
    x = ty;
    y = tx - a / b * ty;
    return v;
}

ll inv(ll a, ll p)
{
    if (!a)
        return 0ll;
    ll x, y;
    exgcd(a, p, x, y);
    x = (x % p + p) % p;
    return x;
}

ll Mul(ll n, ll pi, ll pk)
{
    if (!n)
        return 1ll;
    ll ans = 1ll;
    for (ll i = 2; i <= pk; i++)
        if (i % pi)
            ans = ans * i % pk;
    ans = quick_mod(ans, n / pk, pk);
    for (ll i = 2; i <= n % pk; i++)
    {
        if (i % pi)
            ans = ans * i % pk;
    }
    return ans * Mul(n / pi, pi, pk) % pk;
}

ll exlucas(ll n, ll m, ll p, ll pi, ll pk)
{
    if (m > n)
        return 0ll;
    ll a = Mul(n, pi, pk), b = Mul(m, pi, pk), c = Mul(n - m, pi, pk);
    ll k = 0ll, ans = 0ll;
    for (ll i = n; i; i /= pi)
        k += i / pi;
    for (ll i = m; i; i /= pi)
        k -= i / pi;
    for (ll i = n - m; i; i /= pi)
        k -= i / pi;
    ans = a * inv(b, pk) % pk * inv(c, pk) % pk * quick_mod(pi, k, pk) % pk;
    return ans * (p / pk) % p * inv(p / pk, pk) % p; //中国剩余定理  a[i]*M*x  余数*其他个个素数的乘积*x
}

int main()
{
    ll n, m, p, ans = 0;
    while (cin >> n >> m >> p)
    {
        for (ll x = p, i = 2; i <= p; i++)
        {
            if (x % i == 0)
            {
                ll pk = 1ll;
                while (x % i == 0)
                    pk *= i, x /= i;
                ans = (ans + exlucas(n, m, p, i, pk)) % p;
            }
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}