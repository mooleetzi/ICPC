#include<bits/stdc++.h>
using namespace std;
struct bigInt{
    int d[510]={0};
    int len=0;
    bigInt(){}
    void input(){
        char ch=getchar();
        int tmp[505];
        while(!isdigit(ch)){
            if (ch=='-')
                d[0]=1;
            ch=getchar();
        }
        while(isdigit(ch)){
            tmp[++len]=ch-48;
            ch=getchar();
        }
        for (int i=1;i<=len;i++)
            d[i]=tmp[len-i+1];
    }
    void set(int a[],int len){
        for (int i=1;i<=len;i++)
            d[i]=a[i];
        this->len=len;
    }
    bigInt operator+(const bigInt&x){
        bigInt ans;
        int c[510]={0};
        int l=max(len,x.len);
        for (int i=1;i<=l;i++){
            c[i]+=d[i]+x.d[i];
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
        if (c[l+1])
            ++l;
        ans.set(c,l);
        return ans;
    }
    void print(){
        for (int i=len;i>=1;i--)
            putchar(d[i]+48);
        putchar('\n');
    }
};
int main(int argc, char const *argv[])
{
    bigInt a,b,c;
    a.input();
    b.input();
    c=a+b;
    c.print();
    return 0;
}
