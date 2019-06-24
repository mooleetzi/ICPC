#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn][maxn];
int dis[maxn], vis[maxn];
int n;
int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n;++i)
        for (int j = 1; j <= n;++j)
            cin >> a[i][j];
    for (int i = 1; i <= n;i++)
        dis[i] = a[1][i];
    dis[1] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = -1;
        int minx = 1e9;
        for (int j = 1; j <= n;j++)
            if (!vis[j]&&dis[j]<minx){
                u = j;
                minx = dis[j];
            }
        if (u==-1)
            break;
        vis[u] = 1;
        ans += minx;
        for (int j = 1; j <= n;j++)
            if (!vis[j]&&dis[j]>a[u][j])
                dis[j] = a[u][j];
    }
    cout << ans;
    return 0;
}
