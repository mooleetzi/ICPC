#include<bits/stdc++.h>
using namespace std;
// using ll = long long;
typedef long long  ll;
const int maxn = 1e5 + 10;
const int day = 360;
map<string, int> mp;
string ss[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
ll getDay(int y,int m,int d){
    ll ans = (ll)(y - 2000) * day+(m-1)*30+d;
    return ans;
}
int main(int argc, char const *argv[])
{
    int t;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    mp["Monday"] = 1;
    mp["Tuesday"] =2;
    mp["Wednesday"] = 3;
    mp["Thursday"] = 4;
    mp["Friday"] = 5;
    cin >> t;
    while(t--){
        int y1, m1, d1, y2, m2, d2;
        string s;
        cin >> y1 >> m1 >> d1 >> s>>y2>>m2>>d2;
        int now = mp[s];
        ll day1 = getDay(y1,m1,d1), day2 = getDay(y2,m2,d2);
        if (day1<day2){
            ll cur = (day2 - day1) % 5;
            ll ans = (cur + now) % 5;
            if (!ans)
                ans = 5;
            cout << ss[ans] << "\n";
        }
        else{
            ll cur = (day1 - day2) % 5;
            ll ans = (now+5-cur) % 5;
            if (!ans)
                ans = 5;
            cout << ss[ans] << "\n";
        }
    }
    return 0;
}
