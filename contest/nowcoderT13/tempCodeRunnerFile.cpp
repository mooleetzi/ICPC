#include<bits/stdc++.h>
using namespace std;
using ll=__int128_t;
const int maxn=32;
int n;
ll gcd(ll a,ll b){
    if (!b)
        return a;
    return gcd(b,a%b);
}
ll getFac(ll n){
    ll ans=1;
    for (ll i=2;i<=n;i++)
        ans*=i;
    return ans;
}
ll getNum(ll a[]){
    ll ans=0;
    for (int i=0;i<4;i++){
        ans+=a[i];
    }
    ll r = getFac(ans);
    sort(a, a + 4);
    for (int i = 0; i < 4;i++)
        r /= getFac(a[i]);
    return r;
}
void print(ll x){
    vector<int> s;
    s.clear();
    while (x)
    {
        s.push_back(x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    for (int x:s)
        cout << x;
}
int main(){
    cin>>n;
    ll all=n;
    ll ans=0;
    for (ll i=0;i<=n;i++)
        for (ll j=0;j<=n;j++)
            for (ll k=0;k<=n;k++)
                for (ll m=0;m<=n;m++){
                    if (i+j+k+m==n){
                        if (i+2*j+3*k+4*m>=3*n){
                            ll t[]={i,j,k,m};
                            ans+=getNum(t);
                        }
                    }
                }
    ll t=1;
    for (int i=1;i<=all;i++)
        t*=4;
    if (!ans)
        cout<<"0/1";
    else if (ans==all)
        cout<<"1/1";
    else{
        ll g=gcd(t,ans);
        t/=g;
        ans/=g;
        print(ans);
        cout << "/";
        print(t);
    }
    return 0;
}
