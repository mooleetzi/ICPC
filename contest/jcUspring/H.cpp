#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 5e8 + 10;
ll a, b, c, d;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if (!b){
        x = 1;
        y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main(int argc, char const *argv[])
{
    cin >> a >> b >> c >> d;
    if (d>b)
        swap(b, d), swap(a, c);
    if ((d - b) % __gcd(a, c) != 0)
        cout << "-1";
    else
    {
        ll x, y;
        ll r = exgcd(a, c, x, y);
        ll t = d - b;
        x *= t / r;
        y *= t / r;
        ll cur=c/r;
        x = (x % cur + cur) % cur;
        cout << x * a + b;
    }
    return 0;
}
