#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1010;
int a[maxn];
int dp[maxn][maxn];
int ans[maxn][maxn];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for (int i=1;i<=n;i++)
            scanf("%d",a+i);
        for (int i=1;i<=n;i++)
        for (int j=i-1;j>=1;j--){
                dp[i][j]=dp[i][j+1];
                if(a[j]>a[i])
                    dp[i][j]++;
        }
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                ans[i][j]=ans[i][j-1]+dp[j][i];
//        for (int i=1;i<=n;i++)
//        {
//            for (int j=1;j<=n;j++)
//                printf("%d ",dp[i][j]);
//            printf("\n");
//        }
        for (int i=0;i<m;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",ans[l][r]);
        }
    }
    return 0;
}
