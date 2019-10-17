/*
在计算除法取模的时候，如果除数不是素数， (a/b)%m = (a % (b*m))/b
*/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k, p;
const int maxn = 1e5 + 10;
int prime[maxn], vis[maxn], pcnt;
inline void init()
{
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[pcnt++] = i;
        for (int j = 0; j < pcnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
ll euler(ll x)
{
    ll res = x;
    for (int i = 0; i < pcnt && prime[i] * prime[i] <= x; i++)
    {
        if (x % prime[i] == 0)
        {
            res -= res / prime[i];
            while (x % prime[i] == 0)
                x /= prime[i];
        }
    }
    if (x > 1)
        res -= res / x;
    return res % p;
}
ll qpow(ll a, ll n)
{
    ll res = 1;
    a %= p;
    while (n)
    {
        if (n & 1)
            res = res * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return res;
}

inline ll solve()
{
    ll res = 0;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            if (i * i != n)
                res = (res + euler(n / i) * qpow(n, i - 1) % p + euler(i) * qpow(n, n / i - 1) % p) % p;
            else
                res = (res + euler(i) * qpow(n, i - 1) % p) % p;
        }
    return res % p;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    init();
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        cout << solve() << "\n";
    }
    return 0;
}
