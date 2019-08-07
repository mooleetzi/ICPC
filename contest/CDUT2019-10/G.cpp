#pragma optmize(3)
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const int maxn = 100010;
const int mod = 998244353;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
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

ll fac[maxn];

ll inv[maxn];

void init()
{
    ll p = 1;
    inv[0] = 1;
    inv[1] = 1;
    fac[0] = fac[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        p = (p * i) % mod;
        fac[i] = p;
    }
    for (int i = 2; i < maxn; i++)
        inv[i] = inv[mod % i] * (mod - mod / i) % mod; //O(n)求逆元

    for (int i = 2; i < maxn; i++)
        inv[i] = inv[i - 1] * inv[i] % mod; //扩展到i!的逆元
}
ll C(int n, int m)
{
    if (m > n)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    read(t);
    while (t--)
    {
        int n;
        read(n);
        ll ans = fac[n - 1];
        ll dec = 0;
        for (int i = 1; i < n; i++)
        {
            ll tmp = C(n, i) * fac[(n - 1 - i)] % mod;
            if (i & 1)
                ans = (ans - tmp + mod) % mod;
            else
                ans = (ans + tmp) % mod;
        }
        if (n & 1)
            --ans;
        else
            ++ans;
        write(ans);
        puts("");
    }
    return 0;
}
