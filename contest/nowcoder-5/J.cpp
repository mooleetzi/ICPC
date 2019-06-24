#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9+10;
typedef long long ll;
ll p2,p3,n;
ll ans;
ll solve(){
    double q2=2/p2,q3=3/p3;
    if (q2>=q3)
        ans=n/2*p2+(n%2?min(p2,p3):0);
    else
        ans=n/3*p3+(n%3?min(p2,p3):0);
    return ans;;
}
int main(){
    scanf("%lld%lld%lld",&n,&p2,&p3);
    printf("%lld\n",solve());
    return 0;
}
