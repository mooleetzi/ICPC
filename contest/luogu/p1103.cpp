#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=110;
int n,k;
struct node{
    int h,w;
    node(int hh,int ww){
        h=hh;
        w=ww;
    }
    node(){}
    bool operator<(const node &a)const{
        return h<a.h;
    }
}a[maxn];
int dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        int h,w;
        cin>>h>>w;
        a[i]=node(h,w);
    }
    sort(a+1,a+n+1);
    int all=n-k;
    int ans=0x3f3f3f3f;
    for (int i=2;i<=n;i++){
        for (int j=2;j<=min(all,i);j++){
            dp[i][j]=0x3f3f3f3f;
            for (int k=j-1;k<i;k++)
                dp[i][j]=min(dp[k][j-1]+abs(a[k].w-a[i].w),dp[i][j]);
        }
    }
    for (int i=all;i<=n;i++)
        ans=min(dp[i][all],ans);
    cout<<ans<<"\n";
    return 0;
}
