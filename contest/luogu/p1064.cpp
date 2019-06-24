#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxM=32010;
struct node{
    int v,p,q,im;
    vector<node> sub;
    node(){
        sub.clear();
    }
    node(int x,int y,int z):v(x),p(y),q(z){
        im=x*y;
    }
}a[70];
int m,n;
int dp[70][maxM];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    int tot=0;
    for (int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[i]=node(x,y,z);
        if (a[i].q)
            a[a[i].q].sub.push_back(a[i]);
    }
    for (int i=1;i<=n;i++){
        for (int j=0;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if (!a[i].q){
                if (!a[i].sub.size()){
                    if (j>=a[i].v)
                        dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].v]+a[i].im);
                }
                else if (a[i].sub.size()==1){
                    if (j>=a[i].v+a[i].sub.front().v)
                        dp[i][j]=max(dp[i-1][j-a[i].v-a[i].sub.front().v]+a[i].im+a[i].sub.front().im,dp[i][j]);

                    if (j>=a[i].v)
                        dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].v]+a[i].im);
                }
                else if (a[i].sub.size()==2){
                    if (j>=a[i].v+a[i].sub.front().v+a[i].sub.back().v)
                        dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].v-a[i].sub.front().v-a[i].sub.back().v]+a[i].im+a[i].sub.front().im+a[i].sub.back().im);
                    if (j>=a[i].v+a[i].sub.front().v)
                        dp[i][j]=max(dp[i-1][j-a[i].v-a[i].sub.front().v]+a[i].im+a[i].sub.front().im,dp[i][j]);
                    if (j>=a[i].v+a[i].sub.back().v)
                        dp[i][j]=max(dp[i-1][j-a[i].v-a[i].sub.back().v]+a[i].im+a[i].sub.back().im,dp[i][j]);
                    if (j>=a[i].v)
                        dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].v]+a[i].im);
                }
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    return 0;
}
