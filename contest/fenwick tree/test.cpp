#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define inf -0x3f3f3f3f
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
int mp[1010][1010];
ll a[1010][1010];
int b[1010];

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        mem0(mp);
        mem0(a);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
            for(int j=i-1;j>=1;j--){
                mp[i][j]=mp[i][j+1];
                if(b[j]>b[i])
                    mp[i][j]++;
            }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                printf("%d ",mp[i][j]);
            printf("\n");
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                a[i][j]=a[i][j-1]+mp[j][i];
            }
        int l,r;
        while(m--){
            scanf("%d%d",&l,&r);
            printf("%d\n",a[l][r]);
        }
    }
    return 0;
}
