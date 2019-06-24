#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int a[3][64];
int main(){
    int t;
    cin>>t;
    while(t--){
        ll l,r;
        ll ans=0;
        cin>>l>>r;
        int i=63;
        for(;i>=0;i--)
            if (((l>>i)&1)^((r>>i)&1))
                break;
        for (;i>=0;i--)
            ans|=1<<i;
        cout<<ans<<"\n";
    }
    return 0;
}
