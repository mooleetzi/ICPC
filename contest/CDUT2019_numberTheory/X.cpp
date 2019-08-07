#pragma optimize(3)
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
// using ll = long long;
// using ull = unsigned long long;
// using pa = pair<int, int>;
// using ld = long double;
typedef long long ll;
int n, m, k, mod;
const int maxn = 1e6 + 100;
ll f[maxn];
int phi[maxn], vis[maxn], prime[maxn], cnt;
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
    f[2] = 1;
    for (int i = 3; i < maxn; i++)
        f[i] = f[i - 1] + phi[i];
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    init();
    while (cin >> a && a)
    {
        cout << f[a] << "\n";
    }
    return 0;
}
