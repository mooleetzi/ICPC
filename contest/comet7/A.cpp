#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
const int maxn = 64;
int n, k;
ll p[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int tot = 0;
        ll now = 1;
        cin >> k >> n;
        ll cur = 0;
        if (k == 1)
        {
            cout << n - 1 << "\n";
            continue;
        }
        while (cur < n)
        {

            cur += now;
            p[tot++] = now;
            now *= k;
        }
        int ans = 0;
        if (tot == 2)
        {
            int left = n - (cur - p[tot - 1]);
            if (left > 1)
            {
                cout << 2 << "\n";
                continue;
            }
        }
        if (cur == n)
        {
            ans = (tot - 1) * 2;
        }
        else
        {
            int left = n - (cur - p[tot - 1]);
            if (left > p[tot - 2])
                ans = (tot - 1) * 2;
            else
                ans = (tot - 1) * 2 - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
