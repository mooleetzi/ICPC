#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn = 110;
char s[maxn];
int dp[maxn][maxn];
inline int match(int i,int j){
    if (s[i]=='('&&s[j]==')')
        return 2;
    if (s[i]=='['&&s[j]==']')
        return 2;
    return 0;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>(s+1)&&(strcmp(s+1,"end")!=0)){
        int len = strlen(s + 1);
        memset(dp, 0, sizeof dp);
        for (int i = 1; i < len;i++)
            dp[i][i + 1] = match(i, i + 1);
            for (int sz = 1; sz <= len; sz++)
                for (int i = 1; i + sz <= len; i++)
                {
                    int j = i + sz;
                    dp[i][j] = dp[i + 1][j - 1] + match(i,j);
                    for (int k = i; k < j; k++)
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
        cout << dp[1][len] << "\n";
    }
    return 0;
}
