#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
using ull = long long;
const int mod = 1e9 + 7;
ull a[maxn];
int n;
unordered_map<ull, int> mp;
set<ull> s;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    ull ans = 1;
    for (int i = 0, j; i < n; i = j)
        for (j = i + 1; j < n && a[j] < a[i] + j - i; j++)
            ans = ans * (a[i] + j - i - a[j] + 1) % mod;
    cout << ans << "\n";
    return 0;
}
