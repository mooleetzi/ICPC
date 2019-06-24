#include<bits/stdc++.h>
using namespace std;
const int maxn=5000+50;
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
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    if (f==-1)
        x=-x;
}
struct node{
    int a,b;
    node(){}
    node(int a,int b){
        this->a=a;
        this->b=b;
    }
    bool operator<(const node&c)const{
        return a<c.a;
    }
}t[maxn];
using ll=long long;
int main(){
    int n,m;
    ll ans=0;
    read(n);read(m);
    for (int i=0;i<m;i++){
        int x,y;
        read(x);read(y);
        t[i]=node(x,y);
    }
    sort(t,t+m);
    for (int i=0;i<m;i++){
        if (!n)
            break;
        if (n>=t[i].b){
            n-=t[i].b;
            ans+=t[i].b*t[i].a;
        }
        else{
            ans+=n*t[i].a;
            n=0;
        }
    }
    printf("%d",ans);
    return 0;
}
