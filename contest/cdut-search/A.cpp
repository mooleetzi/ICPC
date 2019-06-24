#include<iostream>
#include<cstring>
#define rep(i,x,y) for (int i=x;i<y;i++)
using namespace std;
int n,k,x;
int ans=0;
int col[10];
char m[10][10];
int judge(int);
void dfs(int);
int main(){
    while(cin>>n>>k&&(k!=-1)&&(n!=-1)){
        ans=0;
        x=0;
        memset(col,-1,sizeof col);
        rep(i,0,n)
            cin>>m[i];
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
int judge(int c){
    rep(i,0,n)
        if (col[i]==c)
            return 0;
    return 1;
}
void dfs(int step){
    if(x==k){
        ans++;
        return;
    }
    if (step==n){
        return;
    }
    for (int i=0;i<n;i++){
        if (m[step][i]=='#'&&judge(i)){
            col[x]=i;
            x++;
            dfs(step+1);
            x--;
            col[x]=-1;
        }
    }
    dfs(step+1);
}
