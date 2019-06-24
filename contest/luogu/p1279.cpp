#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
char s1[2010],s2[2010];
inline int getLen(char a,char b){
    return abs(a-b);
}
int k;
int dp[2010][2010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>s2>>k;
    int l1=strlen(s1);
    int l2=strlen(s2);
    for (int i=0;i<=l1;i++)
        for (int j=0;j<=l2;j++)
            dp[i][j]=inf;
    dp[0][0]=0;
    for (int i=1;i<=l1;i++)
        dp[i][0]=dp[i-1][0]+k;
    for (int i=1;i<=l2;i++)
        dp[0][i]=dp[0][i-1]+k;
    for (int i=1;i<=l1;i++)
    for (int j=1;j<=l2;j++){
        dp[i][j]=min(dp[i][j],dp[i-1][j]+k);
        dp[i][j]=min(dp[i][j],dp[i][j-1]+k);
        dp[i][j]=min(dp[i][j],dp[i-1][j-1]+getLen(s1[i-1],s2[j-1]));
    }
    cout<<dp[l1][l2];
    return 0;
}
