#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
typedef long long ll;
int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
        ll ans=0;
        int mx,my;
        scanf("%d%d%d",&mx,&my,&n);
        while(n--){
            int x,y;
            scanf("%d%d",&x,&y);
            ll t=x<mx-x?x:mx-x;
            t=t<y?t:y;
            t=t<my-y?t:my-y;
            ans+=t;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
