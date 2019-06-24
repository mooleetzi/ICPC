#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull n,q;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> q;
        ull ans;
        if (q==1)
            ans = n;
        else
            ans = n * n;
        while(ans>=10){
            ull now = 0;
            while(ans){
                now += ans % 10;
                ans /= 10;
            }
            ans = now;
        }
        cout << ans << "\n";
    }
    return 0;
}
