#include<bits/stdc++.h>
const int maxn=1e4+10;
int block_size;
struct nod{
    int l,r,bl,br,id,t;
    nod(){}
    nod(int a,int b,int c,int d){
        l=a,r=b,id=c,t=d;
        bl=l/block_size,br=r/block_size;
    }
    bool operator<(const nod &a)const{
        if (bl==a.bl){
            if (br==a.br)
                return t<a.t;
            return br<a.br;
        }
        return bl<a.bl;
    }
}q[maxn];
struct no{
    int pos,val;
}c[maxn];
int ans[maxn];
int cnum;
int num;
int ans1;
int a[maxn],vis[1000100];
void add(int x){
    if (vis[x]==0)
        ans1++;
    vis[x]++;
}
void del(int x){
    if (--vis[x]==0)
        ans1--;
}
void change(int now,int i){
    if (c[now].pos>=q[i].l&&c[now].pos<=q[i].r){
        if (--vis[a[c[now].pos]]==0)
            ans1--;
        if (++vis[c[now].val]==1)
            ans1++;
    }
    std::swap(c[now].val,a[c[now].pos]);
}
int main(){
    int n,m;
    std::cin>>n>>m;
    block_size=(int)sqrt(n);
    for (int i=1;i<=n;i++)
        std::cin>>a[i];
    for (int i=1;i<=m;i++){
        std::string s;
        std::cin>>s;
        if (s[0]=='Q'){
            int x,y;
            std::cin>>x>>y;
            q[++num].l=x;
            q[num].r=y;
            q[num].id=num;
            q[num].bl=x/block_size;
            q[num].br=y/block_size;
            q[num].t=cnum;
        }
        else{
            int x,y;
            std::cin>>x>>y;
            c[++cnum].pos=x;
            c[cnum].val=y;
        }
    }
    std::sort(q+1,q+1+num);
    int l=1,r=0,now=0;
    for (int i=1;i<=num;i++){
        while(l<q[i].l) del(a[l++]);
        while(r<q[i].r) add(a[++r]);
        while(l>q[i].l) add(a[--l]);
        while(r>q[i].r) del(a[r--]);
        while(now<q[i].t) change(++now,i);
        while(now>q[i].t) change(now--,i);
        ans[q[i].id]=ans1;
    }
    for (int i=1;i<=num;i++)
        std::cout<<ans[i]<<"\n";
    return 0;
}
