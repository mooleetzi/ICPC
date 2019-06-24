#include<bits/stdc++.h>
using namespace std;
int cmp(string a,string b){
    if (a.size()>b.size())
        return 1;
    else if (a.size()<b.size())
         return 0;
    for (int i=0;i<a.size();i++)
        if (a[i]>b[i])
            return 1;
        else if (a[i]<b[i])
            return 0;
    return 0;
}
int main(){
    string maxx="0";
    int n,ans;
    cin>>n;
    for (int i=1;i<=n;i++){
        string now;
        cin>>now;
        if (cmp(now,maxx)){
            maxx=now;
            ans=i;
        }
    }
    cout<<ans<<"\n"<<maxx;
    return 0;
}
