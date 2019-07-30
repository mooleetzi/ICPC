#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
using ll = long long;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll left = n * m - 1 - k;
    if (left < n + m - 2)
        cout << -1;
    else
        cout << n + m - 2;
    return 0;
}
