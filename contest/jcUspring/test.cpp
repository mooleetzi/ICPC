#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(), (a).end()
#define fillchar(a, x) memset(a, x, sizeof(a))
#define huan printf("\n")
#define debug(a, b) cout << a << " " << b << " " << endl
#define ffread(a) fastIO::read(a)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1000000009;
const double epx = 1e-6;
const double pi = acos(-1.0);
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = exgcd(b, a % b, x, y);
    ll temp = x;
    x = y;
    y = temp - a / b * y;
    return gcd;
}
int main()
{
    ll a, b, c, d, x, y;
    cin >> a >> b >> c >> d;
    if (b < d)
        swap(b, d), swap(a, c);
    ll gd = exgcd(a, c, x, y);
    if ((d - b) % gd != 0)
        cout << "-1" << endl;
    else
    {
        x *= (d - b) / gd;
        ll t = c / gd;
        x = (x % t + t) % t;
        cout << a * x + b << endl;
        //       ll ans=a*x+b;
        //       ans=min(a*abs(x-t)+
        //       gd=exgcd(c,a,x,y);
        //       x*=(b-d)/gd;
        //       t=a/gd;
        //       x=(x%t+t)%t;
        //       ans=min(x*c+d,ans);
        //       cout<<ans<<endl;
    }
}