#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1100;
int a[maxn][110];
int b[110][30];
int ans[maxn];
int getLcs(int *a,int *b,int la,int lb){
    int dp[la+1][lb+1];
    memset(dp,0,sizeof dp);
    for (int i=1;i<=la;i++)
        for (int j=1;j<=lb;j++)
            if (a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    return dp[la][lb];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        a[i][0]=s.size();
        for (int j=1;j<=a[i][0];j++)
            a[i][j]=s[j-1]-'A'+1;
    }
    for (int i=0;i<m;i++){
        string s;
        cin>>s;
        b[i][0]=s.size();
        for (int j=1;j<=b[i][0];j++)
            b[i][j]=s[j-1]-'A'+1;
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (getLcs(a[i],b[j],a[i][0],b[j][0])==b[j][0])
                ++ans[i];
    for (int i=0;i<n;i++)
        cout<<ans[i]<<"\n";
    return 0;
}
