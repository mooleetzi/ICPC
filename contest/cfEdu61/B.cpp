#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e5 + 10;
int n,m;
ll pre[maxn];
int a[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    sort(a, a + n, [](int x, int y) { return x > y; });
    pre[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    cin >> m;
    for (int i = 0; i < m;i++){
        int x;
        cin >> x;
        ll ans = pre[n - 1];
        ans -= a[x - 1];
        cout << ans << "\n";
    }
    return 0;
}

