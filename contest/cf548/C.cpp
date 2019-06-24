/*
    ans=所有情况（n^k)-红边联通集合的情况(sz[i]^k)
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;
const ll mod = 1e9 + 7;
ll pow(ll x,ll p){
    ll ans = 1;
    while(p){
        if (p&1)
            ans = (ans % mod * x % mod) % mod;
        x = (x % mod) * (x % mod) % mod;
        p >>= 1;
    }
    return ans;
}
inline int read()
{
    register int f = 1, ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
ll n, m,k;
struct dsu
{
    int fa[maxn],rnk[maxn];
    dsu(){
        for (int i = 0; i <=n;i++)
            fa[i] = i;
    }
    int find(int x){
        if (fa[x]==x)
            return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x,int y){
        int tx = find(x), ty = find(y);
        if (tx==ty)
            return;
        fa[tx] = ty;
    }
};
ll sz[maxn];
int main(int argc, char const *argv[])
{
    n = read(), k = read();
    dsu *tr=new dsu();
    for (int i = 0; i < n - 1; i++)
    {
        int x = read(), y = read(), p = read();
        if (!p){
            tr->merge(x, y);
        }
    }
    int ans = pow(n, k);
    for (int i = 1; i <= n;i++)
        ++sz[tr->find(i)];
    for (int i = 1; i <= n;i++)
        if (tr->fa[i]==i)
            ans = (ans - pow(sz[i], k) + mod) % mod;
    cout << ans;
    return 0;
}
