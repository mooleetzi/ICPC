/*
不行 还不会树状数组的区间更新（无法接受
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int c[maxn];
typedef long long ll;
inline int lowbit(int x){
    return (x&-x);
}
void update(int x,int val){
    while(x<maxn){
        c[x]+=val;
        x+=lowbit(x);
    }
}
ll query(int x){
    ll ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    int n,q;
    while(~scanf("%d%d",&n,&q)){
        memset(c,0,sizeof c);
        for (int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            update(i,x);
        }
        char ch;
        int a,b;
        ll c;
        getchar();
        for (int i=0;i<q;i++){
            scanf("%c",&ch);
            if (ch=='Q'){
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(b)-query(a-1));
            }
            else if (ch=='C'){
                scanf("%d%d%lld",&a,&b,&c);
                for (int i=a;i<=b;i++)
                    update(i,c);
            }
            getchar();
        }
    }
    return 0;
}
