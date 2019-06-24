#include <bits/stdc++.h>
using namespace std;
const int maxn=100006;
bool hengvis[maxn],zongvis[maxn];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    bool vismid=false;
    for (int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        hengvis[y]=zongvis[x]=true;
        if(n%2&&x==(n+1)/2&&y==(n+1)/2)
            vismid=true;
    }
    int ans=2*n-(n%2);
    if(n%2)
    {
        for (int i=1;i<=n;i++) {
            if(i==(n+1)/2)  continue;
            if(hengvis[i])  ans--;
            if(zongvis[i])  ans--;
        }
        if(hengvis[(n+1)/2]&&zongvis[(n+1)/2])  ans--;
    }
    else
    {
        for (int i=1;i<=n;i++) {
            if(hengvis[i])  ans--;
            if(zongvis[i])  ans--;
        }
    }
    printf("%d\n",ans);
}

