#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll mol=0,deno=1;
    for (int i=0;i<n;i++){
        ll x,y;
        char c;
        cin>>x>>c>>y;
        ll g=__gcd(deno,y);
        ll m=deno/g*y;
        mol*=m/deno;
        x*=m/y;
        deno=m;
        mol+=x;
    }
    ll g=__gcd(mol,deno);
    mol/=g;
    deno/=g;
    if (deno<0){
        deno=-deno;
        mol=-mol;
    }
    if (deno<0||mol<0)
        cout<<"-";
    deno=abs(deno);
    mol=abs(mol);
    if (mol<deno){
        cout<<mol<<'/'<<deno;
    }
    else if (mol==deno){
        cout<<1<<"\n";
    }
    else{
        cout<<mol/deno;
        if (mol%deno!=0){
            cout<<" "<<mol%deno<<"/"<<deno;
        }
    }
    return 0;
}
