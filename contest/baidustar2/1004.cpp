#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
typedef long long ll;
int a[maxn],t,n;
bool judge(int x){
    ll s1=0,s2=0;
    for (int i=0;i<n;i++){
        if (a[i]>x+1)
            s2+=(a[i]-x)/2;
        else
            s1+=max(0,x-a[i]);
    }
    return s2>=s1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    int ans=0;
    while(t--){
        ans=-1;
        memset(a,-1,sizeof a);
        cin>>n;
        for (int i=0;i<n;i++)
            cin>>a[i];
        int l=0,r=1e8+2;
        while(l<=r){
            int mid=(l+r)>>1;
            if (judge(mid)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
