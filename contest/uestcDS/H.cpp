#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
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
int n, m;
ll a[maxn];
queue<ll>q;
ll ans=-1e12;
int main(int argc, char const *argv[])
{
    n = read(), m = read();
    for (int i = 0; i < n;i++)
        a[i] = read();
    ll pre = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(a[i], ans);
        q.push(a[i]);
        pre += a[i];
        if (q.size()>m){
            pre -= q.front();
            q.pop();
        }
        ans = max(ans, pre);
    }
    cout << ans;
    return 0;
}
