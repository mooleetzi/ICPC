#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=110;
int x,y,k;
int lx[maxn],ly[maxn],visy[maxn],visx[maxn],g[maxn][maxn];
int find(int u){
    for (int i=1;i<y;i++){
        if (!visy[i]&&g[u][i]){
            visy[i]=1;
            if (ly[i]==-1||find(ly[i])){
                lx[u]=i;
                ly[i]=u;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    while(scanf("%d",&x)==1&&x){
        memset(lx,-1,sizeof lx);
        memset(ly,-1,sizeof ly);
        memset(g,0,sizeof g);
        scanf("%d%d",&y,&k);
        int ans=0;
        for (int i=0;i<k;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[b][c]=1;
        }
        for (int i=1;i<x;i++){
            if (lx[i]==-1){
                memset(visy,0,sizeof visy);
                ans+=find(i);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
