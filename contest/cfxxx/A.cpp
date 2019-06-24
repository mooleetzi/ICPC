#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
char s[maxn];
vector<int> a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int len = strlen(s);
    int tot = 0;
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
            a.push_back(i);
    }
    if (a.size() > 2)
        cout << "NO";
    else
    {
        if (a.empty())
            cout << "YES";
        else if (a.size() == 2)
        {
            char s1 = s[a[0]];
            char s2 = s[len - 1 - a[0]];
            char s3 = s[a[1]];
            char s4 = s[len - 1 - a[1]];
            if (s1 == s4 && s2 == s3)
                cout << "YES";
            else
                cout << "NO";
        }
        else if (a.size() == 1)
        {
            if (!(len&1))
                cout << "NO";
            else
            {
                int t1 = 0, t2 = 0;
                for (int i = 0; i < len;i++)
                    if (s[i]==s[a[0]])
                        ++t1;
                    else if (s[i]==s[len-1-a[0]])
                        ++t2;
                if ((t1&1)&&(t2&1))
                    cout << "NO";
                else
                    cout << "YES";
            }
        }
    }
    return 0;
}
