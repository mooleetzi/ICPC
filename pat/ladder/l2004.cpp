#include<iostream>
using namespace std;
const int maxn =1e3+10;
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
int n;
int a[maxn];
int ch[maxn][2];
int val[maxn];
int tot;
int create(int fa){
    int cur=++tot;
    if (cur>n)
        return 0;
    val[cur]=a[cur];
    ch[fa][0]=create(cur);
    ch[fa][1]=create(cur);
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
