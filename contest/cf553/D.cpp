#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int maxn = 1e5 + 10;
struct node
{
    ll a, b;
    bool operator<(const node &x){
        return b - a < x.b - x.a;
    }
}t[maxn];
int n;
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> t[i].a >> t[i].b;
    sort(t + 1, t + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += t[i].a * (i - 1) + t[i].b * (n - i);
    cout << ans;
    return 0;
}
