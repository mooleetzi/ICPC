#include<bits/stdc++.h>
using namespace std;
const int maxn=150;
struct edg{
    int x,y,w,c,v;
    bool operator<(const edg &a)const{
        return w<a.w;
    }
}edge[maxn];
int fa[maxn],n,m;
int find1(int x){
    return ((fa[x]==-1)?x:find1(fa[x]));
}
void kruskal(int k){
    int t1[2],t2[2];
    t1[0]=t1[1]=t2[0]=t2[1]=0;
    if (k<n-1){
        cout<<-1<<"\n";
        return;
    }
    for (int i=1;i<=n;i++) fa[i]=-1;
    int ans1=0,ans2=0;
    for (int i=0;i<m;i++) edge[i].v=0;
    for (int i=0;i<m;i++){
        if (t2[0]<n-1&&(edge[i].c==1||edge[i].c==2)&&!edge[i].v){
            if (edge[i].x==edge[i].y)
                continue;
            int x=find1(edge[i].x);
            int y=find1(edge[i].y);
            if (x!=y){
                fa[x]=y;
                ans1+=edge[i].w;
                t1[0]++;
                t2[0]++;
                edge[i].v=1;
            }
            else
                continue;
        }
    }
    if (t2[0]==n-1)
        for (int i=0;i<m;i++){
            if (t1[0]<k&&!edge[i].v){
                ans1+=edge[i].w;
                edge[i].v=1;
                t1[0]++;
            }
        }
    for (int i=1;i<=n;i++) fa[i]=-1;
    for (int i=0;i<m;i++) edge[i].v=0;
    for (int i=0;i<m;i++){
        if (t2[1]<n-1&&(edge[i].c==3||edge[i].c==2)&&!edge[i].v){
            if (edge[i].x==edge[i].y)
                continue;
            int x=find1(edge[i].x);
            int y=find1(edge[i].y);
            if (x!=y){
                fa[x]=y;
                ans2+=edge[i].w;
                t1[1]++;
                t2[1]++;
                edge[i].v=1;
            }
        }
    }
    if (t2[1]==n-1)
        for (int i=0;i<m;i++){
            if (t1[1]<k&&!edge[i].v){
                ans2+=edge[i].w;
                edge[i].v=1;
                t1[1]++;
            }
        }
    int ans=0;
    if (t2[0]<n-1)
        ans=ans2;
    else if (t2[1]<n-1)
        ans=ans1;
    if (t2[1]<n-1&&t2[0]<n-1)
        ans=-1;
    else
        ans=min(ans1,ans2);
    cout<<ans<<"\n";
}
int main(){
    int t,q=0;
    cin>>t;
    while(q<t){
        cin>>n>>m;
        for (int i=0;i<m;i++){
            char ch;
            cin>>edge[i].x>>edge[i].y>>edge[i].w>>ch;
            if (ch=='R')
                edge[i].c=1;
            else if (ch=='G')
                edge[i].c=2;
            else
                edge[i].c=3;
            edge[i].v=0;
        }
        sort(edge,edge+m);
//        cout<<"\n";
//        for (int i=0;i<m;i++)
//            cout<<edge[i].x<<" "<<edge[i].y<<" "<<edge[i].w<<" "<<edge[i].c<<"\n";
        cout<<"Case #"<<++q<<":\n";
        for (int i=1;i<=m;i++)
            kruskal(i);
    }
    return 0;
}
