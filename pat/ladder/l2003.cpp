#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1100;
struct node
{
    int a,b;
    double c;
    bool operator<(const node&a)const{
        return c>a.c;
    }
}s[maxn];
inline int read(){
    char ch;
    int tmp=0;
    int f=1;
    ch=getchar();
    if (ch=='-'){
        f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        tmp=tmp*10+ch-'0';
        ch=getchar();
    }
    tmp*=f;
    return tmp;
}
int n,m;
int main(){
    n=read(),m=read();
    for (int i=0;i<n;i++)
        s[i].a=read();
    for (int i=0;i<n;i++)
        s[i].b=read();
    for (int i=0;i<n;i++)
        s[i].c=(s[i].b*1.0)/(s[i].a*1.0);
    sort(s,s+n);
    double ans=0;
    for (int i=0;i<n&&m;i++){
        if (m>=s[i].a){
            m-=s[i].a;
            ans+=s[i].b;
        }
        else
        {
            ans+=m*s[i].c;
            m=0;
        }
        
    }
    printf("%.2f",ans);
    return 0;
}