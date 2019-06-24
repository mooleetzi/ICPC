#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof(a))
#define rep2(i,x) for (int i=head[x];~i;i=edge[i].next)
using namespace std;
const int max_vet=1e3+10;
const int max_edge=2e6+100;
const int inf=0x3f3f3f3f;
struct edg{
    int to,next,w;
}edge[max_edge];
int head[max_vet],inq[max_vet],edge_num,vet_num,cnt=0;
int d[max_vet];
void spfa();
void add(int,int,int);
int main(){
    //ios::sync_with_stdio(false);
    int t,q=0;
    scanf("%d",&t);
    while(++q<=t){
        mt(head,-1);
        cnt=0;
        scanf("%d%d",&vet_num,&edge_num);
        rep(i,0,edge_num){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
            add(y,x,z);
        }
//        rep(i,0,vet_num)
//            d[i]=inf;
        spfa();
        cout<<"Scenario #"<<q<<":\n"<<d[vet_num]<<"\n\n";
    }
    return 0;
}
void spfa(){
    mt(inq,0);
    mt(d,0x3f);
    queue<int> que;
    que.push(1);
    d[1]=0;
    inq[1]=1;
    while(!que.empty()){
        int x=que.front();
        que.pop();
        inq[x]=0;
        rep2(i,x){
            int y=edge[i].to;
            if (d[y]<min(d[x],edge[i].w)){
                d[y]=min(d[x],edge[i].w);
                if (!inq[y]){
                    que.push(y);
                    inq[y]=1;
                }
            }
        }
    }
}
void add(int x,int y,int z){
    edge[cnt].to=y;
    edge[cnt].next=head[x];
    edge[cnt].w=z;
    head[x]=cnt++;
}
