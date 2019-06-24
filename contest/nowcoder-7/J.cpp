#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
rope<int> s;
string ss;
int main(){
    int n;
    cin>>n;
    cin>>ss;
    for (int i=0;i<ss.length();i++)
        s.push_back(ss[i]-'0');
    for (int i=0;i<s.size();i++)
        cout<<s[i];
    return 0;
}
