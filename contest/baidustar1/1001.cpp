#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int a[maxn],n;
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n){
        for (int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+1+n);
        int flag=0;
        int ans=0;
        for (int i=n;i>0;i--)
            if (flag)
                break;
            else
            for (int j=i-1;j>0;j--)
            if (flag)
                break;
            else
                for (int k=j-1;k>0;k--)
                    if (i!=j&&j!=k&&k!=i){
                        if (a[i]-a[k]<a[j]&&a[i]-a[j]<a[k]&&a[j]+a[k]>a[i]){
                            ans=a[i]+a[j]+a[k];
                            flag=1;
                            break;
                    }

        }
        if (!ans)
            ans=-1;
        cout<<ans<<"\n";
    }
    return 0;
}
