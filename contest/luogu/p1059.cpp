#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
set<int> s;
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    for (auto x:s)
        cout<<x<<" ";
    return 0;
}
