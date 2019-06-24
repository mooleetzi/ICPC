#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
const int inf=0x3f3f3f3f;
struct node{
    int h,w;
    node(){}
    node(int hh,int ww){
        h=hh;
        w=ww;
    }
    bool operator<(const node&a)const{
        return h<a.h;
    }
}a[maxn];
int dp[maxn][maxn];
int n,k;
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
    for (int i=2;i<=n;i++)
    for (int j=1;j<=min(k,i);j++){
        dp[i][j]=inf;
        for (int q=j;q<i;q++)
            dp[i][j]=min(dp[q][j]+abs(a[q].w-a[i].w),dp[i][j]);
    }
    int ans=inf;
    for (int i=k;i<=n;i++)
        ans=min(ans,dp[i][k]);
    cout<<ans<<'\n';
    return 0;
}
