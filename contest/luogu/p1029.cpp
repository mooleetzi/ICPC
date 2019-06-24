#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ll x, y;
    cin >> x >> y;
    int ans = 0;
    for (ll i = x; i <= y; i++)
    {
        ll tmp = x * y / i;
        if (__gcd(i,tmp)==x&&x*y==i*tmp)
            ++ans;
    }
    cout << ans << "\n";
    return 0;
}