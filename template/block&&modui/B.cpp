#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
typedef long long ll;
int block_size;
ll a[maxn],sum[maxn];
ll n,m,ans;
pair<ll,ll> anss[maxn];
struct node{
    int l,r,block,id;
    node(){}
    node(int a,int b,int c):l(a),r(b),id(c){
        block=l/block_size;
    }
    bool operator<(const node &a)const{
        if (block==a.block)
            return r<a.r;
        return block<a.block;
    }
}queries[maxn];
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        block_size=sqrt(n);
        for (int i=1;i<=n;i++)
            cin>>a[i];
        for (int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            queries[i]=node(x,y,i);
        }
        sort(queries+1,queries+1+m);
        int l=1,r=0;
        ans=0;memset(sum,0,sizeof sum);
        //sum[a[1]]=1;
        for (int i=1;i<=m;i++){
            node now=queries[i];
            //memset(sum,0,sizeof sum);
            pair<ll,ll> &p=anss[queries[i].id];
            p.second=(ll)((now.r-now.l)*(ll)(now.r-now.l+1));
            while(l>now.l){
                l--;
                ans-=(ll)sum[a[l]]*sum[a[l]];
                sum[a[l]]++;
                ans+=sum[a[l]]*sum[a[l]];
            }
            while(l<now.l){
                ans-=sum[a[l]]*sum[a[l]];
                sum[a[l]]--;
                ans+=sum[a[l]]*sum[a[l]];
                l++;
            }
            while(r<now.r){
                r++;
                ans-=sum[a[r]]*sum[a[r]];
                sum[a[r]]++;
                ans+=sum[a[r]]*sum[a[r]];
            }
            while(r>now.r){
                ans-=sum[a[r]]*sum[a[r]];
                sum[a[r]]--;
                ans+=sum[a[r]]*sum[a[r]];
                r--;
            }
            p.first=ans-(ll)(now.r-now.l+1);
            int q=__gcd(p.first,p.second);
            p.first=p.first/q;
            p.second/=q;
        }
        for (int i=1;i<=m;i++){
            cout<<anss[i].first<<"/"<<anss[i].second<<"\n";
        }
    }
    return 0;
}
