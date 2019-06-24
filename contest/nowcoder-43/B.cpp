#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
inline ll read()
{
    register ll f = 1 ;
    
    ll ans = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        ans = (ans << 3) + (ans << 1) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
ll pow(ll a,ll n,ll mod){
    ll ans = 1;
    while(n){
        if (n&1)
            ans = ((a%mod)*(ans%mod))%mod;
        a = (a%mod)*(a%mod)%mod;
        n >>=1;
    }
    return ans;
}
int main()
{
    ll t = read();
    while(t--){
        ll a, b, l, r;
        a = read(), b = read(), l = read(), r = read();
        a = (a * pow(10, l-1, b))%b;
        for (int i = l; i <= r; i++)
        {
            a = (a << 3) + (a << 1);
            printf("%d", a / b);
            a %= b;
        }
        printf("\n");
    }
    return 0;
}