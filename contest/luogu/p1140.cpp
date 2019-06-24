#include<iostream>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int b[150];
int a[5][5]=
{
    {
        5,-1,-2,-1,-3
    },
    {
        -1,5,-3,-2,-4,
    },
    {
        -2,-3,5,-2,-2
    },
    {
        -1,-2,-2,5,-1
    },
    {
        -3,-4,-2,-1,0
    }
};
char s1[110],s2[110];
int dp[110][110];
int main()
{
    b['A']=0;
    b['C']=1;
    b['G']=2;
    b['T']=3;
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l1,l2;
    cin>>l1>>s1;
    cin>>l2>>s2;
    for (int i=1;i<=l1;i++)
        for (int j=1;j<=l2;j++)
            dp[i][j]=-inf;
    for (int i=1;i<=l1;i++)
        dp[i][0]=dp[i-1][0]+a[b[s1[i-1]]][4];
    for (int i=1;i<=l2;i++)
        dp[0][i]=dp[0][i-1]+a[b[s2[i-1]]][4];
    for (int i=1;i<=l1;i++)
    for (int j=1;j<=l2;j++){
        dp[i][j]=max(dp[i][j],dp[i-1][j]+a[b[s1[i-1]]][4]);
        dp[i][j]=max(dp[i][j],dp[i][j-1]+a[b[s2[j-1]]][4]);
        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[b[s1[i-1]]][b[s2[j-1]]]);
    }
    cout<<dp[l1][l2]<<"\n";
    return 0;
}
