#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;
const ll inf = 1e18;
const int maxn = 1e5 + 10;
ll mod, n;
int prime[maxn / 2];
bool vis[maxn];
int cnt = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> mod;
    if (n >= mod || n > 3)
    {
        cout << "0\n";
        return 0;
    }
    ll now = 1;
    for (int i = 2; i <= n; i++)
        now *= i;
    n = now;
    now = 1;
    for (int i = 2; i <= n; i++)
        now *= i;
    n = now;
    now = 1;
    for (int i = 2; i <= n; i++)
        now = now * i % mod;
    cout << now % mod << "\n";
    return 0;
}