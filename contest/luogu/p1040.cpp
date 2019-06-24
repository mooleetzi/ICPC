#include<bits/stdc++.h>
using namespace std;
const int maxn=40;
int a[maxn];
int f[maxn][maxn];
int rt[maxn][maxn];
int n;
inline int read(){
    register int f=1,ans=0;
    char ch=getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        ans=(ans<<3)+(ans<<1)+ch-48;
        ch=getchar();
    }
    return ans*f;
}
void print(int l,int r){
    if (l>r)
        return;
    cout<<rt[l][r]<<" ";
    print(l,rt[l][r]-1);
    print(rt[l][r]+1,r);
}
int main(int argc, char const *argv[])
{
    memset(rt,-1,sizeof rt);
    n=read();
    for (int i=1;i<=n;i++)
        a[i]=read(),f[i][i]=a[i],rt[i][i]=i;
    for (int l=1;l<n;l++)
        for (int i=1;i+l<=n;i++){
            int j=i+l;
            f[i][j]=f[i][i]+f[i+1][j];//默认根节点为开始节点
            rt[i][j]=i;
            for (int k=i+1;k<j;k++)
                if (f[i][k-1]*f[k+1][j]+f[k][k]>f[i][j])
                f[i][j]=f[i][k-1]*f[k+1][j]+a[k],rt[i][j]=k;
        }
    printf("%d\n",f[1][n]);
    print(1,n);
    return 0;
}
