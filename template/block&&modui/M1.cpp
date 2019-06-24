#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int block_size;
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
int a[maxn];
map<int,int> buf;
queue<int> anss[maxn];
inline void add(int x){
    if (buf.count(x))
        buf[x]++;
    else
        buf[x]=1;
}
inline void del(int x){
    if (--buf[x]==0)
        buf.erase(x);
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n,m;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        block_size=(int)(sqrt(n));
        for (int i=1;i<=m;i++){
            int x,y;
            cin>>x>>y;
            queries[i]=node(x,y,i);
        }
        sort(queries+1,queries+m+1);
        int l=1,r=1;
        buf[a[1]]=1;
        for (int i=1;i<=m;i++){
            node now=queries[i];
            while(l<now.l) add(a[++l]);
            while(r>now.r) del(a[r--]);
            while(r<now.r) add(a[++r]);
            while(l>now.l) del(a[l--]);
            queue<int> &ans=anss[queries[i].id];
            map<int,int>::iterator it;
            for (it=buf.begin();it!=buf.end();it++)
                if (it->second>=2)
                    ans.push(it->first);
        }
        for (int i=1;i<=m;i++){
            queue<int> &ans=anss[i];
            if (ans.empty())
                cout<<"-1";
            while(!ans.empty()){
                cout<<ans.front()<<" ";
                ans.pop();
            }
            cout<<"\n";
        }
    }
    return 0;
}
