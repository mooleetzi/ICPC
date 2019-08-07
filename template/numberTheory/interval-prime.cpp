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