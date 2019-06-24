/*ÇóÇ°×ººÍ*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int c[maxn],n,a[maxn];
inline int lowbit(int x){
    return (x&-x);
}
void update(int x,int value){
    while(x<maxn){
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
    memset(c,0,sizeof c);
    memset(a,0,sizeof a);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        update(i,x);
    }

    printf("%d",getSum(n)-getSum(1));
    return 0;
}
