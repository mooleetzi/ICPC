#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for (int i=x;i<y;i++)
using namespace std;
const int maxn=10100;
const int maxnode=110;
typedef long long ll;
struct node{
    int x,y,w;
    bool operator<(const node&a)const{
        return w<a.w;
    }
}edge[maxn];
int f[maxnode];
int find(int x){
    return f[x]==-1?x:f[x]=find(f[x]);
}
int n,m;
void kruskal(){
    sort(edge,edge+n);
    int ans=0,cnt=0;
    for (int i=0;i<n;i++){
        int x=edge[i].x;
        int y=edge[i].y;
        if (find(x)!=find(y)){
            ++cnt;
            f[y]=x;
            ans+=edge[i].w;
        }
    }
    if (cnt==m-1)
        printf("%d\n",ans);
    else
        printf("?\n");
}
int main(){
    while(scanf("%d%d",&n,&m)==2&&n){
        memset(f,-1,sizeof f);
        for (int i=0;i<n;i++)
            scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].w);
        kruskal();
    }
    return 0;
}
