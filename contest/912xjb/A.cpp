#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
#include<stack>
#include<map>
#include<cmath>
#include<string>
#include<vector>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
#define maxn 10000000000010
#define m0(a) memset(a,0,sizeof a)
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int read() {
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9')c = getchar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        putchar(x / y + 48);
        x %= y;
    }
}
ll pow(ll x,ll n)
{
    ll res=1;
	while(n)
	{
	   if(n&1)
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
    ll n,k,ans=0;
    n=read(),k=read();
    for (int i=0;i<10;i++)
        for (int j=0;j<10;j++)
            if (i-j==k)
                ++ans;
    ans=ans+pow(10,n-2);
    write(ans);
    return 0;
}


