#define Local
#define maxn 16384
#define INF 0x3f3f3f3f //int=1061109567,if num is 5, will trans to long type
#define MOD 10000000009
#define scint(x) scanf("%d",&x)
#define scdb(x) scanf("%lf",&x)
#define pint(x) printf("%d",x)
#define pdb(x) printf("%lf",x)
#define pendl printf("\n")
#define per(i,x,y) for(int i=x;i<y;i++)
#define pere(j,x,y) for(int j=x;j<=y;j++)
#define rep(i,x,y) for(int i=x;i>y;i--)
#define repe(j,x,y) for(int j=x;j>=y;j--)
#define mem0(x) memset(x,0,sizeof x)
#define mem(x,y) memset(x,y,sizeof x)
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<iostream>
#include<assert.h>
#include<queue>
#include<string>
typedef long long ll;
typedef unsigned usd;
const double pi = acos(-1);
using namespace std;
usd x,y,z;
usd tang(){
    usd t;
    x ^= x<<16;
    x ^= x>>5;
    x ^= x<<1;
    t=x;
    x=y;
    z=t^x^y;
    return z;
}
usd lcm(usd x,usd y){
    return x*y/__gcd(x,y);
}
int main(){
    int kase=1;
    int T=0;
    //scanf("%d",&kase);
    while(kase--){
        usd a,b,c;
        cin>>a>>b>>c;
        x=a,y=b,z=c;
        cout<<lcm(tang(),tang());
    }
}
