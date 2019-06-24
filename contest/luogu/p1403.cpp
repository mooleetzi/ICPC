#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += n / i;
    cout << ans;
    return 0;
}
