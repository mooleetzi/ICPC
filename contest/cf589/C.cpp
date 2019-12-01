#include <algorithm>
#include <numeric>
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
#define pblank putchar(' ')
#define ll LL
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
ll n, m, k;
const int maxn = 1e6 + 10;
const ll mod = 1e9 + 7;
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
template <typename T>
void _write(const T &t)
{
    write(t);
}
template <typename T, typename... Args>
void _write(const T &t, Args... args)
{
write(t), pblank;
 _write(args...);
}
template <typename T, typename... Args>
inline void write_line(const T &t, const Args &... data)
{
   _write(t, data...);
   puts("");
}
int prime[maxn], vis[maxn], pcnt;
void init(){
    for (int i = 2; i < maxn;i++){
        if (!vis[i])
            prime[pcnt++] = i;
        for (int j = 0; j < pcnt && i * prime[j] < maxn;j++){
            vis[i * prime[j]] = 1;
            if (i%prime[j]==0)
                break;
        }
    }
}
ll fac[maxn], tot;
inline ll qpow(ll base,ll n){
    ll res = 1;
    while(n){
        if(n&1)
            res = res * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return res;
}
ll f(ll n, int p)
{
    if (n == 0)
        return 0;
    return f(n / p, p) + n / p;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    init();
    ll x = read<ll>();
    n = read<ll>();
    for (int i = 0; i < pcnt;i++){
        if (x%prime[i]==0){
            fac[tot++] = prime[i];
            while(x%prime[i]==0)
                x /= prime[i];
        }
    }
    if (x!=1)
        fac[tot++] = x;
    ll res = 1;
    for (int i = 0; i < tot;i++){
        ll t = f(n, fac[i]);
        res = res * qpow(fac[i], t) % mod;
    }
    writeln(res);
    return 0;
}