#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int maxn =1e5+10;
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
struct  node
{
    int addr,key,next,isok;
    node(){
        isok=maxn*2;
    }
    bool operator<(const node&a)const{
        return isok<a.isok;
    }
    /* data */
}a[maxn];
int c1,c2;
set<int> cur;
int main(int argc, char const *argv[])
{
    int s,n;
    s=read(),n=read();
    for (int i=0;i<n;i++){
        int add,k,n;
        add=read(),k=read(),n=read();
        a[add].addr=add,a[add].key=k,a[add].next=n;
    }
    int tmp=s;
    while(tmp!=-1){
        int addr=a[tmp].addr;
        int k=a[tmp].key;
        if (cur.count(abs(k)))
            a[tmp].isok=maxn+c2++;
        else
        {
            a[tmp].isok=c1++;
        }
        tmp=a[tmp].next;
        cur.insert(abs(k));
    }
    sort(a,a+maxn);
    int i;
    for (i=0;i<c1-1;i++)
        printf("%05d %d %05d\n",a[i].addr,a[i].key,a[i+1].addr);
    printf("%05d %d -1\n",a[i].addr,a[i].key);
    for (i=c1;i<c2+c1-1;i++)
        printf("%05d %d %05d\n",a[i].addr,a[i].key,a[i+1].addr);
    printf("%05d %d -1\n",a[i].addr,a[i].key);
    return 0;
}
