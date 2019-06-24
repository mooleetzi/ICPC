#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
using ll = long long;
ll ans = 0, n;
int a[maxn], b[maxn], c[maxn];
inline int lowbit(int x)
{
    return x & (-x);
}
void add(int i,int val){
    while(i<maxn){
        c[i] += val;
        i += lowbit(i);
    }
}
ll query(int x){
    ll ans = 0;
    while (x)
    {
        ans += c[x];
        x -= lowbit(x);
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
        ans = (ans << 3) + (ans << 1) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
int main(int argc, char const *argv[])
{
    n = read();
    for (int i = 1; i <= n;i++){
        a[i] = read();
        b[i] = a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n;i++)
        b[i] = lower_bound(a + 1, a + 1 + n, b[i]) - a;
    for (int i = 1; i <= n; i++)
    {
        add(b[i], 1);
        ans += i - query(b[i]);
    }
    printf("%lld", ans);
    return 0;
}
