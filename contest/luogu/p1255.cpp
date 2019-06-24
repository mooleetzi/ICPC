#include<bits/stdc++.h>
using namespace std;
const int maxn=5050;
int f[maxn];
struct bigInt
{
    int d[maxn]={0};
    int len=0;
    bigInt(){}
    bigInt(int x){
        d[1]=x;
        len=1;
    }
    void set(int a[],int len){
        for (int i=0;i<=len;i++)
            d[i]=a[i];
        this->len=len;
        for (int i=len+1;i<maxn;i++)
            d[i]=0;
    }
    bigInt operator+(const bigInt &x){
        int tmp[maxn]={0};
        int l=max(len,x.len);
        for (int i=1;i<=l;i++){
            tmp[i]+=d[i]+x.d[i];
            tmp[i+1]+=tmp[i]/10;
            tmp[i]%=10;
        }
        if (tmp[l+1])
            ++l;
        bigInt ans;
        ans.set(tmp,l);
        return ans;
    }
    void print(){
        for (int i=len;i>=1;i--)
            putchar(d[i]+48);
        putchar('\n');
    }

};
inline int read(){
    register int f=1,ans=0;
    char ch=getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        ans=(ans<<3)+(ans<<1)+ch-48;
        ch=getchar();
    }
    return ans*f;
}
int main(int argc, char const *argv[])
{
    int n=read();
    bigInt a(1),b(2),c(0);
    for (int i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    if (n==1)
        c=a;
    else if (n==2)
        c=b;
    c.print();
    return 0;
}
