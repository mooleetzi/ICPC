#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 10;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    string s;
    cin >> n >> x >> y;
    cin >> s;
    int ans = 0;
    reverse(s.begin(), s.end());
    if (s[y]=='0'){
        ++ans;
        s[y] = '1';
    }
    for (int i = 0; i < x;i++)
        if (i!=y)
            ans += s[i] - '0';
    cout << ans;
    return 0;
}