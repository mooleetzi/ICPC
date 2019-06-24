#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[35][35];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    dp[0][1]=1;
    dp[1][2]=1;
    dp[1][n]=1;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++){
            if (j==1)
                dp[i][j]=dp[i-1][n]+dp[i-1][2];
            else if (j==n)
                dp[i][j]=dp[i-1][n-1]+dp[i-1][1];
            else
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
        }
    cout<<dp[m][1];
    return 0;
}
