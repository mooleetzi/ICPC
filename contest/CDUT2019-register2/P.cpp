/*
    每个数对答案的贡献都是n*f(x,x)
    累加即可
*/
#pragma optmize(2)
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
const int mod = 998244353;
template <class T>
inline T read()
{
    int f = 1;
    T ret = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = (ret << 1) + (ret << 3) + ch - '0';
        ch = getchar();
    }
    ret *= f;
    return ret;
}
template <class T>
inline void write(T n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        write(n / 10);
    }
    putchar(n % 10 + '0');
}
ll a[maxn];
ll f(ll x, ll y)
{
    vector<int> t;
    t.clear();
    while (x)
    {
        t.emplace_back(y % 10);
        t.emplace_back(x % 10);
        x /= 10;
        y /= 10;
    }
    reverse(t.begin(), t.end());
    ll res = 0;
    int sz = t.size();
    for (int i = 0; i < sz; i++)
        res = (res * 10 + t[i]) % mod;
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 1; i <= n; i++)
        a[i] = read<ll>();
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = (res + f(a[i], a[i]) * n % mod) % mod;
    }
    write(res);
    return 0;
}