#include<bits/stdc++.h>
using namespace std;
const int maxn=1e9+10;
const int mod=19260817;
typedef long long ll;
ll get(int x){
    int a=1,b=2,c=4;
    int ans=0;
    for (int i=3;i<=x;i++){
        if (a>=mod)
            a-=mod;
        if (b>=mod)
            b-=mod;
        if (c>=mod)
            c-=mod;
        ans=a+b+c;
        if (ans>=mod)
            ans-=mod;
        a=b;
        b=c;
        c=ans;
    }
    return ans;
}
int f[3];
int main(){
    int n,m;
    f[0]=1;
    f[1]=2;
    f[2]=4;
    scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        if (n<3)
            printf("%d\n",f[n]);
        else printf("%d\n",get(n)%mod);
    }
    return 0;
}
