#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1e5+10;
int n;
int dp[maxn],vis[maxn];
int main(){
    vector<int> a;
    ios::sync_with_stdio(false);
    freopen("1.txt","r",stdin);
    int t;
    int x;
    cin>>t;
    while(cin>>x){
        a.push_back(x);
    }
    memset(dp,0,sizeof dp);
    memset(vis,0,sizeof vis);
    dp[0]=1;
    for (int i=0;i<a.size();i++)
        for (int j=t;j>=a[i];j--)
                dp[j]+=dp[j-a[i]];
    for (int i=1;i<=t;i++)
        cout<<dp[i]<<"\n";
    //cout<<dp[t]<<"\n";
    return 0;
}
