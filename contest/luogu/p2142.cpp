#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
struct bigInt{
    int d[maxn]={0};
    int len=0;
    void input(){
        char ch=getchar();
        int tmp[maxn];
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
        for (int i=len+1;i<maxn;i++)
            d[i]=0;
    }
    void print(){
        if (d[0])
            putchar('-');
        for (int i=len;i>=1;i--)
            putchar(d[i]+48);
        putchar('\n');
    }
    bigInt operator-(bigInt x){
        bigInt ans;
        int tmp[maxn]={0};
        int f=is_big(x);
        if (f<0){
            bigInt t=*this;
            set(x.d,x.len);
            x.set(t.d,t.len);
            tmp[0]=1;
        }
        int l=max(len,x.len);
        for (int i=1;i<=l;i++){
            tmp[i]+=d[i]-x.d[i];
            if (tmp[i]<0){
                tmp[i]+=10;
                --tmp[i+1];
            }
        }
        while(!tmp[l]&&l-1){
            --l;
        }
        ans.set(tmp,l);
        return ans;
    }
    int is_big(const bigInt&x){
        if (len>x.len)
            return 1;
        if (len<x.len)
            return -1;
        for (int i=len;i>=1;i--)
            if (d[i]<x.d[i])
                return -1;
            else if (d[i]>x.d[i])
                return 1;
        return 0;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    bigInt a,b,c;
    a.input();
    b.input();
    c=a-b;
    c.print();
    return 0;
}
