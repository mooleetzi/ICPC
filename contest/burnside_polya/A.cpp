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
int n, m, k;
const int maxn = 1e5 + 10;
ll qpow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll solve()
{
    ll res = 0;
    if (!n)
        return res;
    for (int i = 1; i <= n; i++)
    {
        res += qpow(3, gcd(n, i));
    }
    if (n & 1)
    {
        res += (ll)n * qpow(3, (n + 1) / 2);
    }
    else
    {
        res += (ll)(n / 2) * qpow(3, (n + 2) / 2);
        res += (ll)(n / 2) * qpow(3, n / 2);
    }
    return res / (2 * n);
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
    while (cin >> n && n != -1)
    {
        cout << solve() << '\n';
    }
    return 0;
}
