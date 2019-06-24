#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=200000+20;
struct nod{
    int w,index,step;
    bool operator<(const nod &a)const{
        return w<a.w;
    }
}node[maxn];
bool cmp(const nod&a,const nod&b){
    return a.w<b.w;
}
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for (int i=1;i<=t;i++){
        int x;
        cin>>x;
        node[i].w=x;
        node[i].step=0;
        node[i].index=i;
    }
    sort(node+1,node+1+t,cmp);
    priority_queue<nod> que;
    int q=1;
    for (int i=0;i<2*t;i++){
        char ch;
        cin>>ch;
        if (ch=='0'){
            cout<<node[q].index<<" ";
            que.push(node[q++]);
        }
        else{
            cout<<que.top().index<<" ";
            que.pop();
        }
    }
    return 0;
}
