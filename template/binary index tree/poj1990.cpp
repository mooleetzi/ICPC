#include<iostream>
#include<cstring>
#include<algorithm>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=2e4+10;
typedef long long ll;
struct sz{
    ll c[maxn];
    sz(){
        memset(c,0,sizeof c);
    }
    void add(ll x,ll v){
        while(x<maxn){
            c[x]+=v;
            x+=lowbit(x);
        }
    }
    ll sum(ll x){
        ll ans=0;
        while(x){
            ans+=c[x];
            x-=lowbit(x);
        }
        return ans;
    }
};
struct node{
    ll v,x;
    bool operator<(const node&a)const{
        return v<a.v;
    }
}a[maxn];
ll ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    sz cnt,dis;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i].v>>a[i].x;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++){
        ll sump=cnt.sum(a[i].x);
        ll sumx=dis.sum(a[i].x);
        ans+=a[i].v*((sump*a[i].x-sumx)+(dis.sum(maxn-1)-sumx-(i-1-sump)*a[i].x));
        cnt.add(a[i].x,1);
        dis.add(a[i].x,a[i].x);
    }
    cout<<ans<<"\n";
}

