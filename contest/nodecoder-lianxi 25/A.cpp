#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e7+10;
typedef long long ll;
ll ans[maxn];
int main(){
    int q;
    scanf("%d",&q);
    memset(ans,0,sizeof ans);
    for (int i=1;i<=q;i++){
        int t;
        scanf("%d",&t);
        ll ansq=0;
        for (int j=1;j<=t;j++)
            ansq+=floor(t/j);
        printf("%lld\n",ansq);
    }
    return 0;
}
