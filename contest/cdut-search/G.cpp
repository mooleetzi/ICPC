#include<iostream>
#include<cstring>
#include<queue>
#define rep(i,x,y) for (int i=x;i<y;i++)
#define mt(a,x) memset(a,x,sizeof a)
using namespace std;
struct node{
    string s1,s2;
    int step;
    node(){}
    node(string a,string b,int c):s1(a),s2(b),step(c){}
};
string s1,s2,s;
int l;
int ans=0;
void bfs();
int main(){
    int t;
    ios::sync_with_stdio(false);
    cin>>t;
    int q=1;
    while(q<=t){
        cin>>l;
        cin>>s1>>s2;
        cin>>s;
        bfs();
        cout<<q++<<" "<<ans<<"\n";
    }
    return 0;
}
void bfs(){
    queue<node> que;
    que.push(node(s1,s2,0));
    while(!que.empty()){
        node now=que.front();
        que.pop();
        if (now.step>2*l)
            break;
        string a=now.s1;
        string b=now.s2;
        string c="";
        rep(i,0,l){
            c+=b[i];
            c+=a[i];
        }
        if (c==s){
            ans=now.step+1;
            return;
        }
        a=b="";
        rep(i,0,l)
            a+=c[i];
        rep(i,l,2*l)
            b+=c[i];
        que.push(node(a,b,now.step+1));
    }
    ans=-1;
    return;
}
