#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double eps = 1e-6;
const int maxn = 2e5 + 10;
const ll inf = 1e18;
using pa = pair<ll, ll>;
multiset<pa> s;
set<pa> ss;
int a[maxn], b[maxn];
int n,f;
ll p[11];
int getNum(int x)
{
    if (!f){
        p[0] = 1;
        for (int i = 1; i < 11;i++)
            p[i] = p[i - 1] * 10;
        f = 1;
    }
    int ans = 0;
    while (x){
        ++ans;
        x /= 10;
    }
    return x;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (a[i]){
            int g = __gcd(a[i], b[i]);
            s.insert(pa(a[i] / g, -b[i] / g));
        }
        else if (!a[i]&&b[i])
            s.insert(pa(inf,inf));
        else if (!a[i]&&!b[i]){
            ++q;
        }
    }
    int ans = 0;
    for (auto x : s)
    {
        if (x.first!=inf&&!ss.count(x)){
            ans = max(ans, (int)s.count(x));
            ss.insert(x);
        }
    }
    cout << ans+q;
    return 0;
}
