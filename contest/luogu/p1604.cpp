#include<bits/stdc++.h>
using namespace std;
const int maxn=2050;
int base;
char s[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int get_num(char c){
    if (isdigit(c))
        return c-48;
    return c-'A'+10;
}
struct bigInt{
    char d[maxn]={'0'};
    int len=0;
    bigInt(){
        for (int i=1;i<maxn;i++)
            d[i]='0';
    }
    void input(){
        char tmp[maxn];
        cin>>tmp;
        len=strlen(tmp);
        for (int i=1;i<=len;i++)
            d[i]=tmp[len-i];
    }
    void print(){
        for (int i=len;i>=1;i--)
            putchar(d[i]);
        putchar('\n');
    }
    void set(char s[],int len){
        for (int i=1;i<=len;i++)
            d[i]=s[i];
        this->len=len;
        for (int i=len+1;i<maxn;i++)
            d[i]='0';
    }
    bigInt operator+(bigInt&x){
        bigInt ans;
        int l=max(len,x.len);
        char tmp[maxn]={'0'};
        for (int i=1;i<=maxn;i++)
            tmp[i]='0';
        for (int i=1;i<=l;i++){
            int t=get_num(d[i])+get_num(x.d[i]);
            tmp[i]=s[get_num(tmp[i])+t];
            if (get_num(tmp[i])>=base){
                int r=get_num(tmp[i]);
                tmp[i]=s[r%base];
                tmp[i+1]=s[get_num(tmp[i+1])+r/base];
            }
        }
        if (get_num(tmp[l+1]))
            ++l;
        ans.set(tmp,l);
        return ans;
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
    cin>>base;
    bigInt a,b,c;
    a.input();
    b.input();
    c=a+b;
    c.print();
    return 0;
}
