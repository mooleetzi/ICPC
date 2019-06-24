#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define debug printf("%d %s",_LINE_,_FUNCTION_)
const int maxn=110;
struct node{
    int x,y,w;
    bool operator<(const node &a)const{
        return w<a.w;
    }
}edge[maxn];
int fa[maxn];
int find(int x){
    return x==fa[x]?x:find(fa[x]);
}
void merge(int x,int y){
//    while(fa[x]!=y){
//        fa[x]=y;
//        x=fa[x];
//    }
    fa[x]=y;
}
int n,m;
int kruskal(){
    int ans=0;
    std::sort(edge,edge+m);
    int q=0;
    for (int i=0;i<m;i++){
        int x=edge[i].x;
        int y=edge[i].y;
        if (find(x)!=find(y)){
            ans+=edge[i].w;
            merge(x,y);
            ++q;
        }
    }
    if (q!=n-1)
        return -1;
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            fa[i]=i;
        for (int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            edge[i]={x,y,z};
        }
        int ans=kruskal();
        if (ans==-1)
            printf("Not Unique!\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
