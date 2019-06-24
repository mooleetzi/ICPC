#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxm=1000;
int fa[11];
int n,m;
struct node{
    int x,y,w;
    node(){}
    node(int x,int y,int z){
        this->x=x;
        this->y=y;
        this->w=z;
    }
    int operator<(const node&a)const{
        return w<a.w;
    }
}edge[maxm];
int find(int x){
    return (x==fa[x]?x:fa[x]=find(fa[x]));
}
int kruskal(){
    int cnt=0;
    int ans=0;
    sort(edge,edge+m);
    for (int i=0;i<m;i++){
        int x=find(edge[i].x);
        int y=find(edge[i].y);
        if (x!=y){
            ans+=edge[i].w;
            fa[y]=x;
            cnt++;
        }
    }
    if (cnt<n-1)
        return -1;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>m){
        for (int i=1;i<=n;i++) fa[i]=i;
        for(int i=0;i<m;i++)
            cin>>edge[i].x>>edge[i].y>>edge[i].w;
        cout<<kruskal()<<"\n";
    }
    return 0;
}
