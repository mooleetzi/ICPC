#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
int a[maxn][maxn];
int dis[maxn],vis[maxn],n;
int dijkstra(){
    for (int i=1;i<=n;i++)
        dis[i]=a[1][i];
    int ans=0;
    for (int i=1;i<n;i++){
        int u=-1,mins=0x3f3f3f3f;
        for (int j=1;j<=n;j++)
            if (!vis[j]&&dis[j]<mins)
                mins=dis[u=j];
        vis[u]=1;
        for (int j=1;j<=n;j++){
            if (!vis[j]&&dis[j]>dis[u]+a[u][j])
                dis[j]=dis[u]+a[u][j];
        }
    }
    for (int i=1;i<=n;i++)
        ans=dis[i]>ans?dis[i]:ans;
    return  ans;
}
int read(){
    char s[11];
    cin>>s;
    if (s[0]=='x')
        return 0x3f3f3f3f;
    else{
        int ans=0,i=0;
        while(i<strlen(s)){
            ans=ans*10+s[i++]-48;
        }
        return ans;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++)
            if (i==j)
                a[i][j]=0;
            else
                a[i][j]=a[j][i]=read();
    cout<<dijkstra();
    return 0;
}

