#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    vector<string> ans;
    string cur;
    getline(cin, cur);
    stringstream s(cur);
    while(s>>cur){
        if (cur=="henan")
            cur = "Henan";
        ans.emplace_back(cur);
    }
    for (auto x:ans)
        cout << x << " ";
    return 0;
}
