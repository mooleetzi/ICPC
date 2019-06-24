#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int x[maxn],y[maxn];
int n,m,ans=0;
int main(){
    memset(x,0,sizeof x);
    memset(y,0,sizeof y);
    scanf("%d%d",&n,&m);
    ans=n<<1;
    for (int i=0;i<m;i++){
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        if (!x[tx]){
            ans--;
            x[tx]=1;
        }
        if (!y[ty]){
            ans--;
            y[ty]=1;
        }
    }
    if (n&1&&!x[n/2+1]&&!y[n/2+1])
        ans--;
    cout<<ans<<"\n";
    return 0;
}
