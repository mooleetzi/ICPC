#include<iostream>
#include<vector>
using namespace std;
vector<string> ans;
int main(){
    int n;
    string s;
    cin>>n;
    cin.get();
    getline(cin,s);
    int tot=0;
    while(tot<s.size()){
        string cur=s.substr(tot,n);
        if (tot+n>=s.size())
            for (int i=0;i<tot+n-s.size();i++)
                cur+=" ";
        ans.push_back(cur);
        tot+=n;
    }
    for (int i=0;i<n;i++){
        for (int j=ans.size()-1;j>0;j--)
            cout<<ans[j][i];
        cout<<ans[0][i]<<"\n";
    }
    return 0;
}
