#include<iostream>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
int main(){
    int n,x,s;
    ios::sync_with_stdio(false);
    while(cin>>n>>s){
        long long ans=0;
        int mid=n/2+1;
        for (int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        int l=lower_bound(a,a+n,s)-a;
        int r=upper_bound(a,a+n,s)-a-1;
        if (l+1>mid){
            int c=l+1-mid;
            int t=l-1;
            while(c--){
                ans+=(long long)s-a[t--];
            }
        }
        else if (mid>r+1){
            int c=mid-r-1;
            int t=r+1;
            while(c--)
                ans+=(long long)a[t++]-s;
        }
        cout<<ans<<"\n";
    }
}
