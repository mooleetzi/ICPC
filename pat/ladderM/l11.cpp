#include<iostream>
#include<set>
#include<vector>
using namespace std;
set<string> all;
vector<string> ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int m;
        cin>>m;
        for (int j=0;j<m;j++){
            string x;
            cin>>x;
            if (m==1)
                continue;
            all.insert(x);
        }
    }
    cin>>n;
    for (int i=0;i<n;i++){
        string now;
        cin>>now;
        if (!all.count(now))
            ans.push_back(now);
        all.insert(now);
    }
    if (ans.empty()){
        cout<<"No one is handsome";
    }
    else{
        for (int i=0;i<ans.size()-1;i++)
            cout<<ans[i]<<" ";
        cout<<ans.back();
    }
    return 0;
}
