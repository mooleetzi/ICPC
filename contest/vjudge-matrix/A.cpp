#include<bits/stdc++.h>
using namespace std;
const int mod=9973;
typedef long long ll;
struct matrix{
    ll m[12][12];
    matrix(){
        memset(m,0,sizeof m);
    }
    matrix operator*(const matrix &a)const{
        matrix c;
        for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++){
            c.m[i][j]=0;
            for (int k=1;k<=10;k++)
                c.m[i][j]+=(m[i][k]*a.m[k][j])%mod;
        }
        return c;
    }
};
matrix quick(matrix base,int p){
    matrix a;
    for (int i=1;i<=10;i++) a.m[i][i]=1;
    while(p){
        if (p&1)
            a=base*a;
        base=base*base;
        p>>=1;
    }
    return a;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        matrix base;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                cin>>base.m[i][j];
        matrix a=quick(base,m);
        ll ans=0;
        for (int i=1;i<=n;i++)
            ans+=(a.m[i][i]%mod);
        cout<<ans%mod<<"\n";
    }
    return 0;
}
