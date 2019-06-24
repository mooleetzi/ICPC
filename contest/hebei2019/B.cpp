#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
ll mod, n, q;
void mul(ll a[][2],ll b[][2]){
    ll temp[2][2];
    for (int i = 0; i < 2;i++)
        for (int j = 0; j < 2;j++){
            temp[i][j] = 0;
            for (int k = 0; k < 2;k++){
                temp[i][j] = (temp[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    for (int i = 0; i < 2;i++)
        for (int j = 0; j < 2;j++)
            a[i][j] = temp[i][j];
}
void quickPow(ll a[][2], ll ans[][2], int n)
{
    ans[0][0] = 1;
    ans[1][1] = 1;
    ans[1][0] = 0;
    ans[0][1] = 0;
    while(n){
        if (n&1)
            mul(ans, a);
        mul(a, a);
        n >>= 1;
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> q >> n>>mod;
        ll a[2][2];
        a[0][0] = 1;
        a[0][1] = 1;
        a[1][0] = 0;
        a[1][1] = q;
        ll ans[2][2];
        quickPow(a,ans,n-1);
        ll cur = (q % mod * q % mod) % mod;
        cout << ((ans[0][0] * (q%mod)) % mod + (ans[0][1] * cur) % mod)%mod << "\n";
    }
    return 0;
}
