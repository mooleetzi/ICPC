#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1000;
using ll = long long;
struct node
{
    ll a, b, c;
    /* data */
}q[maxn];
bool cmp(node x,node y){
    return x.c * y.b < x.b * y.c;
}
ll n,t;
ll dp[maxn];
int main(int argc, char const *argv[])
{
    cin >> t >> n;
    for (int i = 1; i <= n;i++)
        cin >> q[i].a;
    for (int i = 1; i <= n;i++)
        cin >> q[i].b;
    for (int i = 1; i <= n;i++)
        cin >> q[i].c;
    sort(q + 1, q + 1 + n,cmp);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = t; j-q[i].c>=0;j--){
            dp[j] = max(dp[j], dp[j - q[i].c] + q[i].a - j * q[i].b);
            ans = max(ans, dp[j]);
        }
    cout << ans;
    return 0;
}
