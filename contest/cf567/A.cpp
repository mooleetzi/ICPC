#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll x, y, ans = 0,minx=0;
    x = a % c, y = b % c;
    ans = a / c + b / c;
    ll cur = x + y;
    if (cur/c){
        ++ans;
        minx = c - max(x, y);
    }
    cout << ans << " " << minx << "\n";
    return 0;
}