#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    x=0;
    register int f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+ch-48;
        ch=getchar();
    }
    if (f==-1)
        x=-x;
}
const int maxn =1e3+10;
struct node{
    int x,ind;
    node(int a,int b){
        x=a;
        ind=b;
    }
    node(){}
    bool operator<(const node &a)const{
        if (x==a.x)
            return ind<a.ind;
        return x<a.x;
    }
}t[maxn];
int main(){
    int n;
    double ans=0;
    read(n);
    for (int i=0;i<n;i++){
        int x;
        read(x);
        t[i]=node(x,i+1);
    }
    sort(t,t+n);
    int tmp=0;
    for (int i=0;i<n;i++){
        if (i){
            ans+=tmp+t[i-1].x;
            tmp+=t[i-1].x;
        }
        printf("%d ",t[i].ind);
    }
    ans/=n;
    printf("\n%.2f",ans);
    return 0;
}
