/*
    暴力打表
 */
#pragma optimize(3)
// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
// using ll = long long;
// using ull = unsigned long long;
// using pa = pair<int, int>;
// using ld = long double;
typedef long long ll;
typedef unsigned long long ull;
int n, m, k, mod;
const int maxn = 1e6 + 100;
ll f[maxn];
int phi[maxn], vis[maxn], prime[maxn], cnt;
unsigned long long maxx = (1ULL << 64ULL) - 1;
set<ull> s;
ull qpow(ull a, int b)
{
    ull res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
void init()
{
    phi[1] = 1;
    int cnt = 0;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
        {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * phi[prime[j]]; // phi[i]*(prime[j]-1);
            }
        }
    }

    s.insert(1);
    for (ull i = 2; i < (1 << 16); i++)
    {
        ull tmp = i * i * i;
        int j = 4;
        while (1)
        {
            tmp *= i;
            if (vis[j])
                s.insert(tmp);
            ++j;
            if (tmp > maxx / i)
                break;
        }
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    freopen("out.txt", "w", stdout);
    init();
    for (auto x : s)
        cout << x << "\n";
    return 0;
}
