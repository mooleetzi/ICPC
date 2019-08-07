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
const int maxn = 2e7 + 2;
const int maxx = 2e7 + 1;
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

int phi[maxn];
ll ans[maxx];
int prime[maxx];
int vis[maxx];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    memset(vis, false, sizeof(vis));
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
    for (int i = 1; i < maxx; i++)
        if (i & 1)
            ans[i] = ans[i - 1] + (phi[i] >> 1);
        else
            ans[i] = ans[i - 1] + phi[i];
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}