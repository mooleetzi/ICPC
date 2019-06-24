//LIS，目前只会o(n^2)算法
//此题数据规模在20w，只能用o(nlogn)哒
#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof a)
using namespace std;
const int maxn=200000+10;
int a[maxn],f[maxn],n,ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rep(i,1,n+1)
        cin>>a[i];
    f[1]=a[1];
    int len=1;
    rep(i,2,n+1){
        if (a[i]>f[len])
            f[++len]=a[i];
        else{
            int j=upper_bound(f+1,f+len+1,a[i])-f;
            f[j]=a[i];
        }
    }
    cout<<len<<"\n";
    return 0;
}
