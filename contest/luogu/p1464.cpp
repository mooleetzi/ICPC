#include<iostream>
using ll=long long;
using namespace std;
int dp[21][21][21];
ll w(ll a,ll b,ll c){
    if (a<=0||b<=0||c<=0)
        return 1;
    if (a>20||b>20||c>20){
        if (!dp[20][20][20])
            return dp[20][20][20]=w(20,20,20);
        return dp[20][20][20];
    }
    if (a<b&&b<c){
        if (!dp[a][b][c])
            return dp[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        return dp[a][b][c];
    }
    if (!dp[a][b][c])
        dp[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    return dp[a][b][c];
}
int main(){
    ll x,y,z;
    while(cin>>x>>y>>z&&(x+y+z!=-3)){
        cout<<"w("<<x<<", "<<y<<", "<<z<<") = "<<w(x,y,z)<<"\n";
    }
    return 0;
}
