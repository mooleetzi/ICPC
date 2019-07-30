#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
using ll = long long;
const ll inf = 1e18;
ll a[maxn];
ll n, k;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        if (abs(a[i] - a[i - 1]) >= k)
            continue;
        else
        {
            a[i] = inf;
            ++ans;
        }
    }
    cout << ans << "\n";
    return 0;
}
