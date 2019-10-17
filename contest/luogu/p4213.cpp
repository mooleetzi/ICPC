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
const int maxn = 5e6 + 10;
unordered_map<int, ll> phi, mu;
int prime[maxn], vis[maxn], pcnt;
ll sum1[maxn];
int sum2[maxn];
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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
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
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
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