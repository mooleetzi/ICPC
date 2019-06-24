#include<iostream>
#include<cstring>
#include<cstdio>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof(a))
#define maxn 32005
using namespace std;
int c[maxn+10],ans[maxn+10];
inline int lowbit(int x){
    return (x&-x);
}
void update(int x,int value){
    while(x<=maxn){
        c[x]+=value;
        x+=lowbit(x);
    }
}
int getSum(int x){
    int ans=0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        mt(ans,0);
        mt(c,0);
        rep(i,0,n){
            int x,y;
            scanf("%d%d",&x,&y);
            x++;
            ans[getSum(x)]++;
            update(x,1);
        }
        rep(i,0,n)
            printf("%d\n",ans[i]);
    }
    return 0;
}
