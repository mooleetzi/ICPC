#include<iostream>
#include<cstring>
#include<queue>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof a)
using namespace std;
void bfs();
int n;
long long ans=0;
struct node{
    long long s;
};
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n&&n){
        bfs();
        cout<<ans<<"\n";
    }
    return 0;
}
void bfs(){
    long long s=1;
    queue<long long> que;
    que.push(s);
    while(!que.empty()){
        s=que.front();
        que.pop();
        s*=10;
        que.push(s);
        if (s%n==0){
            ans=s;
            return;
        }
        s++;
        que.push(s);
        if (s%n==0){
            ans=s;
            return;
        }
    }
}
