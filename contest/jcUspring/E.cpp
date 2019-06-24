#include<bits/stdc++.h>
using namespace std;
map<string, int> m1, m2;
set<string> all;
using ll = long long;
int main(int argc, char const *argv[])
{
    string s;
    getline(cin, s);
    int pre = 0;
    
    for (int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
        if (s[i] == ' ')
        {
            string now = s.substr(pre, i-pre);
            pre = i + 1;
            ++m1[now];
            all.insert(now);
        }
    }
    string now = s.substr(pre, s.size()-pre);
    ++m1[now];
    all.insert(now);
    getline(cin, s);
    pre = 0;
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
        if (s[i] == ' ')
        {
            string now = s.substr(pre, i - pre);
            pre = i + 1;
            ++m2[now];
            all.insert(now);
        }
    }
    now = s.substr(pre, s.size() - pre);
    ++m2[now];
    all.insert(now);
    double s1 = 0, s2 = 0;
    vector<int> q1, q2;
    q1.clear(), q2.clear();
    for (auto x : all)
    {
        // cout << x << "\n";
        s1 += m1[x] * m1[x];
        s2 += m2[x] * m2[x];
        q1.emplace_back(m1[x]);
        q2.emplace_back(m2[x]);
    }
    double deno = 0;
    for (int i = 0; i < q1.size(); i++)
    {
        deno += q1[i] * q2[i];
    }
    if (deno/(sqrt(s1)*sqrt(s2))>=0.9)
        cout << "Yes";
   else
   {
       cout << "No";
   }
//    cout << (1.0*deno / (sqrt(s1) * sqrt(s2)));
   return 0;
}
