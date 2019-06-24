#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int vis[26];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        auto last = unique(s.begin(), s.end());
        if (last!=s.end()){
            cout << "No\n";
            continue;
        }
        int f = 1;
        for (int i = 1; i < s.size();i++)
            if (s[i]!=s[i-1]+1){
                f = 0;
                break;
            }
        if (f)
            cout << "Yes\n";
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
