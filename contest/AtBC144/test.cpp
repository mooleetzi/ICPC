#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

const long double PI = (acos(-1));
const long double EPS = 0.0000000001;

long double a, b, x;

void input()
{
    cin >> a >> b >> x;
}

long double f(long double a, long double b, long double x)
{
    long double ans;
    if (a * a * b / 2.0 <= x)
    {
        ans = atan(2 * (a * a * b - x) / (a * a * a));
    }
    else
    {
        ans = PI / 2 - atan(2 * x / (a * b * b));
    }
    return ans;
}

void solve()
{
    input();
    cout << fixed << setprecision(10) << f(a, b, x) * 180.0 / PI << endl;
    return;
}

int main()
{
    solve();
    return 0;
}