//未过
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=3010;
struct node{
    int index;
    int p;
    node(){}
    node(int i,int p):index(i),p(p){}
    bool operator<(const node&a)const{
        return p>a.p;
    }
};
int n;
priority_queue<node> que;
int vis[maxn];
int flag=0;
int dfs(int now){
    node q=que.top();
    que.pop();
    if (q.index==n-1){
        que.push(q);
        flag=1;
        if (now>q.p)
            return now^q.p;
        else
            return 0;
    }
    if (now>q.p)
        return max(dfs(now^q.p),dfs(now));
    que.push(q);
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    int s;
    for (int i=0;i<n;i++){
        int p;
        cin>>p;
        if (!i)
          s=p;
        else
            que.push(node(i,p));
    }
    int ans=dfs(s);
    if (ans==0||flag==0)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
