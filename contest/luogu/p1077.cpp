#include<iostream>
#include<algorithm>
using namespace std;
const int inf=1000007;
typedef long long ll;
ll dp[200][200];
int a[200];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
            for (int k=0;k<=a[i];k++)
                if (j+k<=m){
                    dp[i][j+k]+=dp[i-1][j];
                    dp[i][j+k]%=inf;
                }
    cout<<dp[n][m]%inf;
}
