#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1001;
const ll mod=1000000007;
ll pow(ll x,ll n,ll mod)
{
    ll res=1;
	while(n>0)
	{
	   if(n%2==1)
	   {
	   	 res=res*x;
	   	 res=res%mod;
	   }
	   x=x*x;
	   x=x%mod;
	   n>>=1;
	}
	return res;
}
int main(){
    ll n,m;
    scanf("%lld%lld",&n,&m);
    m--;
    n--;
    ll ans=((pow(m,n,mod)%mod)*((m+1)%mod))%mod;
    printf("%lld",ans);
    return 0;
}
