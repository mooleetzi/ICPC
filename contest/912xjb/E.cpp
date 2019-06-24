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
#define maxn 1000100
#define m0(a) memset(a,0,sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
ull pow(ull x,ull n)
{
    ull res=1;
	while(n)
	{
	   if(n&1)
	   {
	   	 res=res*x;
	   }
	   x=x*x;
	   n>>=1;
	}
	return res;
}
ull a,b;
int main(){
    int n,m;
    n=read(),m=read();
    a=pow(2,n);
    b=pow(2,m);
    ull ans=(b-a)/7;
    ull x=a+((b-a)/7)*7,y=b;
    for (ull i=x;i<y;i++)
        if (i%y==1)
            ++ans;
    write(ans);
    return 0;
}


