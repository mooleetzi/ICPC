#include<bits/stdc++.h>
using namespace std;
char s[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXTZ";
int main(int argc, char const *argv[])
{
    int n,base;
    cin>>n>>base;
    cout<<n<<"=";
    vector<char>ans;
    ans.clear();
    while(n){
        int m=n%base;
        if (m<0){
            n+=base;
            m-=base;
        }
        ans.emplace_back(s[m]);
        n/=base;
    }
    reverse(ans.begin(),ans.end());
    for (auto x:ans)
        cout<<x;
    cout<<"(base"<<base<<")";
    // cout<<((-4)%(-6))<<" "<<25/(-6);
    return 0;
}
