#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int a[10];
inline void getDigit(int x){
    while(x){
        a[x % 10]++;
        x /= 10;
    }
}
ll quickPow(ll x,ll n){
    ll ans = 1;
    while(n){
        if (n&1){
            ans *= x%mod;
            ans %= mod;
        }
        x *= x%mod;
        x %= mod;
        n >>= 1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        memset(a, 0, sizeof a);
        int l, r;
        cin >> l >> r;
        if (r-l>=9)
            cout << 0 << "\n";
        else{
            for (int i = l; i <= r;i++)
                getDigit(i);
            if (a[0])
                cout << "0\n";
            else{
                ll ans = 1;
                for (int i = 2; i <= 9;i++){
                    ans *= quickPow(i, a[i]) % mod;
                    ans %= mod;
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}