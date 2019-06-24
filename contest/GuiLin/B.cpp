#include<bits/stdc++.h>
using namespace std;
set<string> s;
int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        string ss;
        cin >> ss;
        s.insert(ss);
    }
    cout << s.size();
    return 0;
}
