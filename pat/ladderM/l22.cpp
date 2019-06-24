#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
const int maxn=1010*15;
int v[maxn];
double a[maxn];
int tot;
int w,n;
double num[maxn],price[maxn];
int p[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
double dp[maxn];
int getItem(int n){
    double single=price[n]*1.0/num[n];
    for (int i=0;i<=15;i++)
    if (p[i]>num[n]){
        for (int j=0;j<i-1;j++){
            a[++tot]=p[j]*single;
            v[tot]=p[j];
        }
        int last=num[n]-p[i-1]+1;
        a[++tot]=last*single;
        v[tot]=last;
        break;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>w;
    for (int i=1;i<=n;i++)
        cin>>num[i];
    for (int i=1;i<=n;i++)
        cin>>price[i];
    for (int i=1;i<=n;i++)
        getItem(i);
    for (int i=1;i<=tot;i++)
        for (int j=w;j>=v[i];j--)
            dp[j]=max(dp[j],dp[j-v[i]]+a[i]);
    cout<<fixed<<setprecision(2)<<dp[w]<<"\n";
    return 0;
}
