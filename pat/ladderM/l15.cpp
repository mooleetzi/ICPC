#include<iostream>
#include<vector>
using namespace std;
vector<int> ans;
int main(){
    int n,m;
    cin>>n>>m;
    int cur=n*m;
    while(cur){
        ans.push_back(cur%10);
        cur/=10;
    }
    int flag=1;
    for (auto x:ans)
        if (!x&&flag)
            continue;
        else{
            cout<<x;
            flag=0;
        }
    return 0;
}
