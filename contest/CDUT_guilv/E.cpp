#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=21;
long double d[maxn];
int main(){
    double ans;
    ans=0;
    int t;
    scanf("%d",&t);
    d[1]=1;
    for (int i=2;i<=maxn;i++)
        d[i]=d[i-1]*i;
    while(t--){
        ans=0;
        int n;
        scanf("%d",&n);
        int op=1;
        for (int i=2;i<=n;i++)
            ans+=op*1/d[i],op*=-1;
        ans*=100;
        printf("%.2f%\n",ans);
    }
    return 0;
}
