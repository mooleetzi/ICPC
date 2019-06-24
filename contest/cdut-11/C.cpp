#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int maxn=25050;
const int maxnode=510;
int a[maxnode][maxnode];
int head[maxnode],ind[maxnode],inq[maxnode];
int n,m;
void solve(){
    priority_queue<int,vector<int>,greater<int> >ans;
    while(!ans.empty())
        ans.pop();
    int f=1;
    for (int i=1;i<=n;i++)
        if (!ind[i])
            ans.push(i);
    while(!ans.empty()){
        int u=ans.top();
        ans.pop();
        if (f)
            printf("%d",u),f=0;
        else
            printf(" %d",u);
        for (int i=1;i<=n;i++)
            if (a[u][i]&&--ind[i]==0)
                ans.push(i);
    }
    printf("\n");
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(a,0,sizeof a);
        memset(ind,0,sizeof ind);
        for (int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if (!a[x][y])
                a[x][y]=1,ind[y]++;
        }
        solve();
    }
}
