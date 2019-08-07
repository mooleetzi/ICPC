/*
    求n!种p因子的个数
 */
ull f(ull n, int p)
{
    if (n == 0)
        return 0;
    return f(n / p, p) + n / p;
}

/*
    euler(x)=x*(1-1/p1)*(1-1/p2)...
            =x*(p1-1)/p1*(p2-1)/p2
    公式法直接求
    note:一个数的所有质因子之和是euler(n)*n/2
 */

int euler(int x)
{
    int res = x, n = x;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}

/*
    筛选法
 */
const int maxn = 1e5 + 10;
int e[maxn];
void getEuler()
{
    for (int i = 1; i < maxn; i++)
        e[i] = i;
    for (int i = 2; i < maxn; i++)
        if (e[i] == i)
            for (int j = i; j < maxn; j += i)
                e[j] = e[j] / i * (i - 1);
}

/*
欧拉法筛素数
 */

for (int i = 2; i <= maxn; i++)
{
    if (!vis[i])
        prime[pcnt++] = i;
    for (int j = 0; j < pcnt && i * prime[j] <= maxn; j++)
    {
        vis[i * prime[j]] = 1;
        if (i % prime[j] == 0)
            break;
    }
}

/*
    Miller-Rabin大素数测试
 */
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
    区间素数筛，maxn是区间长度，[a,b]
 */
const int maxn = 1e5 + 10; //区间最大长度
bool isprime1[maxn], isprime2[maxn];
int solve(ll a, ll b)
{
    for (ll i = 0; i * i <= b; i++)
        isprime1[i] = 0;
    for (ll i = 0; i <= b - a; i++)
        isprime2[i] = 1;
    for (ll i = 2; i * i <= b; i++)
    {
        if (!isprime1[i])
        {
            for (ll j = i + i; j * j <= b; j += i)
                isprime1[j] = 1;
            for (ll j = max(2LL, (a + i - 1) / i) * i; j <= b; j += i)
                isprime2[j - a] = 0;
        }
    }
    int sum = 0;
    for (int i = 0; i <= b - a; i++)
        if (isprime2[i])
            sum++;
    if (a == 1)
        --sum;
    return sum;
}