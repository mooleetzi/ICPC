#include<bits/stdc++.h>
using namespace std;
using pa=pair<int,int>;
vector<pa> a;
int cmp(pa a,pa b){
    if (a.second==b.second)
        return a.first<b.first;
    return a.second>b.second;
}
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.emplace_back(pa(x,y));
    }
    sort(a.begin(),a.end(),cmp);
    vector<pa> ans;
    ans.clear();
    m=floor(m*1.5);
//    cout<<m<<"\n";
    cout<<a[m-1].second<<" ";
    for (int i=0;i<n;i++)
    if (a[i].second>=a[m].second){
        ans.emplace_back(a[i]);
    }
    cout<<ans.size()<<"\n";
    for (auto x:ans)
        cout<<x.first<<" "<<x.second<<"\n";
    return 0;
}
