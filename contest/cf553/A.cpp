#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
char s[maxn];
int getSuc(char a,char b){
    int ans = (a - b + 26) % 26;
    int ans1 = 26 - ans;
    return min(ans1,ans);
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cin >> s;
    int ans = 1e9;
    for (int i = 0; i+3<n; i++)
    {
        int tmp = 0;
        tmp += getSuc('A', s[i]);
        // cout << tmp << "\n";
        tmp += getSuc('C', s[i + 1]);
        // cout << tmp << "\n";
        tmp += getSuc('T', s[i + 2]);
        // cout << tmp << "\n";
        tmp += getSuc('G', s[i + 3]);
        // cout << tmp << "\n";
        ans = min(tmp, ans);
    }
    cout << ans;
    return 0;
}
