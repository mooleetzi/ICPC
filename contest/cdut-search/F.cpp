#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof a)
using namespace std;
void bfs();
int vis[10010];
int s,e,ans=0;
struct node{
    int s,step;
    node(){}
    node(int a,int b):s(a),step(b){}
};
bool pri[10010];
void prime();
int main(){
    int t;
    ios::sync_with_stdio(false);
    prime();
    cin>>t;
    while(t--){
        cin>>s>>e;
        if (s==e)
            cout<<"0\n";
        else{
            bfs();
            cout<<ans<<"\n";
        }
    }
    return 0;
}
void prime(){
    mt(pri,false);
    for (int i=1;i<10000;i+=2)
        pri[i]=true;
    for (int i=0;i<10000;i+=2)
        pri[i]=false;
    pri[1]=false;pri[2]=true;
    for (int i=2;i<10000;i++)
    if (pri[i]){
        for (int j=2*i;j<10000;j+=i)
            pri[j]=false;
    }
    return;
}
void bfs(){
    mt(vis,0);
    queue<node> que;
    que.push(node(s,0));
    vis[s]=1;
    while(!que.empty()){
        node now=que.front();
        que.pop();
        int q=now.s;
        int x=q;
        int a[4];
        mt(a,0);
        int j=0;
        while(x){
            a[3-j++]=x%10;
            x/=10;
        }
        rep(i,1,10){
            x=i*1000+a[1]*100+a[2]*10+a[3];
            if (x==e){
                ans=now.step+1;
                return;
            }
            if (!vis[x]&&pri[x]){
                que.push(node(x,now.step+1));
                vis[x]=1;
            }
        }
        rep(i,0,10){
            x=a[0]*1000+i*100+a[2]*10+a[3];
            if (x==e){
                ans=now.step+1;
                return;
            }
            if (!vis[x]&&pri[x]){
                que.push(node(x,now.step+1));
                vis[x]=1;
            }
        }
        rep(i,0,10){
            x=a[0]*1000+a[1]*100+i*10+a[3];
            if (x==e){
                ans=now.step+1;
                return;
            }
            if (!vis[x]&&pri[x]){
                que.push(node(x,now.step+1));
                vis[x]=1;
            }
        }
        for(int i=1;i<10;i+=2){
            x=a[0]*1000+a[1]*100+a[2]*10+i;
            if (x==e){
                ans=now.step+1;
                return;
            }
            if (!vis[x]&&pri[x]){
                que.push(node(x,now.step+1));
                vis[x]=1;
            }
        }
    }
}
