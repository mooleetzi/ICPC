#include<bits/stdc++.h>
using namespace std;
struct bigInt{
    int d[5050]={0};
    int len=0;
    bigInt(){}
    void input(){
        char ch=getchar();
        int tmp[5050];
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
        this->len=len;
        for (int i=0;i<=len;i++)
            d[i]=a[i];
    }
    bigInt operator*(const bigInt&x){
        int tmp[5050]={0};
        tmp[0]=d[0]^x.d[0];
        for (int i=1;i<=len;i++)
            for (int j=1;j<=x.len;j++){
                tmp[i+j-1]+=d[i]*x.d[j];
                tmp[i+j]+=tmp[i+j-1]/10;
                tmp[i+j-1]%=10;
            }
        int l=len+x.len;
        while(!tmp[l]&&l-1){
            --l;
        }
        bigInt ans;
        ans.set(tmp,l);
        return ans;
    }
    void print(){
        if (d[0])
            putchar('-');
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
    c=a*b;
    c.print();
    return 0;
}
