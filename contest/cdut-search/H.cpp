#include<iostream>
#include<cstring>
#include<queue>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof a)
using namespace std;
const int maxn=1e3+10;
int a,b,c;
struct node{
    int a,b,step,op,pre;
    node(){}
    node(int z,int x,int v,int n,int m):a(z),b(x),step(v),op(n),pre(m){}
}que[maxn];
string opt[]={"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};
void solve(int,int,int);
void print();
bool vis[210][210];
void bfs();
int l,r;
int ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin>>a>>b>>c;
    bfs();
    if (ans==-1)
        cout<<"impossible";
    else{
        cout<<ans<<"\n";
        print();
    }
    return 0;
}
void bfs(){
    l=0,r=1;
    que[0].a=0;
    que[0].b=0;
    que[0].op=-1;
    que[0].step=0;
    que[0].pre=-1;
    vis[0][0]=true;
    while(l!=r){
        int aa,bb;
        if (que[l].a==c||que[l].b==c){
            ans=que[l].step;
            return;
        }
        aa=a;bb=que[l].b;
        solve(aa,bb,0);
        aa=que[l].a,bb=b;
        solve(aa,bb,1);
        aa=0,bb=que[l].b;
        solve(aa,bb,2);
        aa=que[l].a;bb=0;
        solve(aa,bb,3);
        aa=que[l].a;bb=que[l].b;
        if (aa>=(b-bb)){
            aa-=(b-bb);
            bb=b;
        }
        else{
            aa=0;
            bb+=aa;
        }
        solve(aa,bb,4);
        aa=que[l].a;bb=que[l].b;
        if(bb>=(a-aa)){
            bb-=(a-aa);
            aa=a;
        }
        else{
            bb=0;
            aa+=bb;
        }
        solve(aa,bb,5);
        l++;
    }
    if (l>=r)
        ans=-1;
    return;
}
void solve(int a,int b,int op){
    if(vis[a][b])
        return;
    que[r].a=a;
    que[r].b=b;
    que[r].op=op;
    que[r].pre=l;
    que[r].step=que[l].step+1;
    vis[a][b]=true;
    r++;
}
void print(){
    int p[maxn];
    mt(p,0);
    int i=ans;
    while(que[l].pre!=-1){
       p[--ans]=que[l].op;
       l=que[l].pre;
    }
    for (int j=0;j<ans;j++)
        cout<<opt[p[j]]<<"\n";
    return;
}
