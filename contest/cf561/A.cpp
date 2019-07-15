#include<iostream>
using namespace std;
using ll = long long;
const int maxn = 1e2 + 5;
int n;
int a[26], b[26];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        string s;
        cin >> s;
        int op = s[0] - 'a';
        if (a[op]<b[op])
            ++a[op];
        else
            ++b[op];
    }
    ll ans = 0;
    for (int i = 0; i < 26;i++){
        if (a[i])
            ans += (a[i] * (a[i] - 1))/2;
        if (b[i])
            ans += (b[i]*(b[i] - 1))/2;
    }
    cout << ans;
    return 0;
}
