#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        string ans = "";
        for (int i = 0; i < s.size();i+=2)
            ans += s.substr(i, 1);
        cout << ans << "\n";
    }

    return 0;
}
