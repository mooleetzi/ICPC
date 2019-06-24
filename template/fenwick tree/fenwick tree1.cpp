#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=25001;
int c[maxn],a[maxn];
inline int lowbit(int x){
    return (x&-x);
}
void update(int x,int val){
    while(x<maxn){
        c[x]+=val;
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
struct node{
    int val,index;
    bool operator<(const node&a)const{
        return (val<a.val);
    }
}info[maxn];
int main(){
    int n;
    while((scanf("%d",&n))==1&&n){
        long long ans=0;
        memset(c,0,sizeof c);
        memset(a,0,sizeof a);
        for (int i=0;i<n;i++){
            scanf("%d",&info[i].val);
            info[i].index=i+1;
        }
        sort(info,info+n);
        for (int i=0;i<n;i++){
            update(info[i].index,1);
            ans+=(info[i].index-getSum(info[i].index));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
