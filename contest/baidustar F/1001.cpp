#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define INF 0x3f3f3f3f
#define MOD 10000000009
typedef long long ll;;
using namespace std;
struct node{
    ll w;
    int pos;
    int operator<(const node &a)const{
        return w<a.w;
    }
}b[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,fa[maxn],vis[maxn];
        memset(fa,0,sizeof fa);
        fa[1]=1;
        scanf("%d",&n);
        for(int i=2;i<=n;i++){
            scanf("%d",&fa[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%lld",&b[i].w);
            b[i].pos=i;
        }
        ll mmax=0,mmin=0;
        sort(b+1,b+n+1);
        memset(vis,0,sizeof vis);
        int flg=0;
        for(int i=1;i<=n;i++){
            if(b[i].w>0) break;
            if(fa[b[i].pos]!=b[i].pos){
                if(vis[fa[b[i].pos]]>=2&&!flg) continue;
                if(vis[fa[b[i].pos]]>=1&&flg) continue;
                vis[fa[b[i].pos]]++;
                if(vis[fa[b[i].pos]]==2) flg=1;
            }
            mmin+=b[i].w;
        }
        flg=0;
        memset(vis,0,sizeof vis);
        for(int i=n;i>=1;i--){
            if(b[i].w<0) break;
            if(fa[b[i].pos]!=b[i].pos){
                if(vis[fa[b[i].pos]]>=2&&!flg) continue;
                if(vis[fa[b[i].pos]]>=1&&flg) continue;
                vis[fa[b[i].pos]]++;
                if(vis[fa[b[i].pos]]==2) flg=1;
            }
            mmax+=b[i].w;
        }
        printf("%lld %lld\n",mmax,mmin);
    }
}
