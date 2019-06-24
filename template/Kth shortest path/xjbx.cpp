#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=2e5+10;
int n;
typedef long long ll;
struct node{
    int l,r,index;
    int operator<(const node &a)const{
        if (l==a.l)
            return r<a.r;
        return l<a.l;
    }
}a[maxn];
ll sum[maxn];
int solve(){
    memset(sum,0,sizeof sum);
    sort(a,a+n);
    for (int i=0;i<n;i++)
        cout<<i+1<<" "<<a[i].l<<" "<<a[i].r<<"\n";
    int cnt=0,tmp=0;
    sum[0]=a[0].r-a[0].l+1;
    for (int i=1;i<n;i++){
        node pre=a[i-1];
        node now=a[i];
        if(now.l==pre.l){
            sum[i]=sum[i-1]+now.r-pre.r;
            return pre.index;
        }
        else{
            if (now.r<=pre.r)
                sum[i]=sum[i-1];
            else if (now.l<=pre.r)
                sum[i]=sum[i-1]+now.r-pre.r;
            else if (now.l>pre.r)
                sum[i]=sum[i-1]+now.r-now.l+1;
        }
    }
    for (int i=0;i<n-1;i++)
        if (sum[i]==sum[i+1])
            return a[i+1].index;
        else if ((i&&sum[i-1]+1==sum[i]&&sum[i]+1==sum[i+1]))
            return a[i].index;

    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        a[i]={l,r,i+1};
    }
    cout<<solve();
    return 0;
}
