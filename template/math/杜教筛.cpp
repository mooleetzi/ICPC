/*
    计算mu和phi的前缀和
    求f前缀和F(n)
    构造h=f*g
    g(1)S(n)=H(n)-[g(2)S(n/2)+g(3)S(n/3)+...g(n)S(1)]
*/
int n, m, k;
const int maxn = 5e6 + 10;
unordered_map<int, ll> phi, mu;
int prime[maxn], vis[maxn], pcnt;
ll sum1[maxn];
int sum2[maxn];
void init()
{
    sum1[1] = 1;
    sum2[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
        {
            prime[pcnt++] = i;
            sum2[i] = -1;
            sum1[i] = i - 1;
        }
        for (int j = 0; j < pcnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                sum1[i * prime[j]] = sum1[i] * prime[j];
                sum2[i * prime[j]] = 0;
                break;
            }
            else
            {
                sum1[i * prime[j]] = sum1[i] * sum1[prime[j]];
                sum2[i * prime[j]] = -sum2[i];
            }
        }
    }
    for (int i = 1; i < maxn; i++)
        sum1[i] += sum1[i - 1], sum2[i] += sum2[i - 1];
}
ll calPhi(int n)
{
    if (n < maxn)
        return sum1[n];
    if (phi.count(n))
        return phi[n];
    ll tmp = (ll)(n) * (n + 1) / 2;
    ll r1 = 0;
    for (int i = 2, j; i >= 0 && i <= n; i = j + 1)
    {
        j = n / (n / i);
        r1 += (j - i + 1) * calPhi(n / i);
    }
    return phi[n] = tmp - r1;
}
ll calMu(int n)
{
    if (n < maxn)
        return sum2[n];
    if (mu.count(n))
        return mu[n];
    ll tmp = 1;
    ll r1 = 0;
    for (int i = 2, j; i >= 0 && i <= n; i = j + 1)
    {
        j = n / (n / i);
        r1 += (j - i + 1) * calMu(n / i);
    }
    return mu[n] = tmp - r1;
}
int main(int argc, char const *argv[])
{
    init();
    int t = read<int>();
    while (t--)
    {
        int n = read<int>();
        write(calPhi(n));
        putchar(' ');
        writeln(calMu(n));
    }
    return 0;
}