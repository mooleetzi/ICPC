#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 10;
ll n,k,nowx,nowy,ans;
char s[maxn];
inline ll man(ll x,ll y){
    return abs(x) + abs(y);
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        nowx = nowy = ans = 0;
        for (int i = 0; i < n;i++){
            if (s[i]=='U')
                ++nowy;
            else if (s[i]=='D')
                --nowy;
            else if (s[i]=='L')
                --nowx;
            else if (s[i]=='R')
                ++nowx;
            ans = max(ans, man(nowx, nowy));
        }
        nowx *= (k - 1);
        nowy *= (k - 1);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'U')
                ++nowy;
            else if (s[i] == 'D')
                --nowy;
            else if (s[i] == 'L')
                --nowx;
            else if (s[i] == 'R')
                ++nowx;
            ans = max(ans, man(nowx, nowy));
        }
        cout << ans << "\n";
    }
    return 0;
}
