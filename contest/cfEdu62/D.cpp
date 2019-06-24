#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(int argc, char const *argv[])
{
    ll n, ans = 0;
    cin >> n;
    for (int i = 2; i < n;i++)
        ans += i * (i + 1);
    cout << ans;
    return 0;
}
