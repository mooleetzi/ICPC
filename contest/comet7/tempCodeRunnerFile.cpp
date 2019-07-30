#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;
const ll inf = 1e18;
const int maxn = 1e5 + 10;
ll mod, n;
int prime[maxn / 2];
bool vis[maxn];
int cnt = 0;
void init()
{
    int m = sqrt(maxn);
    for (int i = 2; i <= m; i++)
    {
        if (!vis[i])
        {
            for (int j = i * 2; j <= maxn; j += i)
            {
                vis[j] = true;
            }
        }
    }
    for (int i = 2; i <= maxn; i++)
        if (!vis[i])
            prime[cnt++] = i;
}
ll poww(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}
ll poww(ll a, ll b, int)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a % mod) % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans % mod;
}
ll getAns(ll n)
{
    ll ans = 1;
    for (int i = 0; i < cnt && prime[i] <= n; i++)
    {
        ll k = 0;
        ll t = n;
        while (t)
        {
            k += t / prime[i];
            t /= prime[i];
        }
        ans = ans * poww(prime[i], k);
        if (ans >= mod)
            return inf;
    }
    return ans;
}
ll getAns(ll n, int)
{
    ll ans = 1;
    for (int i = 0; i < cnt && prime[i] <= n; i++)
    {
        ll k = 0;
        ll t = n;
        while (t)
        {
            k += t / prime[i];
            t /= prime[i];
        }
        ans = ans * poww(prime[i], k, 0) % mod;
    }
    return ans % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> mod;
    if (n >= mod || n > 3)
    {
        cout << "0\n";
        return 0;
    }
    ll now = 1;
    for (int i = 2; i <= n; i++)
        now *= i;
    n = now;
    now = 1;
    for (int i = 2; i <= n; i++)
        now *= i;
    n = now;
    now = 1;
    for (int i = 2; i <= n; i++)
        now = now * i % mod;
    cout << now << "\n";
    return 0;
}