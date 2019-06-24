#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<string> out;
    set<string> all;
    set<string> handsome;
    set<string> query;
    out.clear();
    all.clear();
    handsome.clear();
    query.clear();
    int n,m;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>m;
        for (int j=0;j<m;j++){
            string x;
            cin>>x;
            if (m!=1)
                all.insert(x);
        }
    }
    cin>>n;
    for (int i=0;i<n;i++){
        string x;
        if (query.count(x))
            continue;
        query.insert(x);
        if (!all.count(x))
            out.emplace_back(x);
    }
    if (out.empty())
        cout<<"No one is handsome";
    else{
        for (int i=0;i<out.size()-1;i++)
            cout<<out[i]<<" ";
        cout<<out.back();
    }
    return 0;
}
