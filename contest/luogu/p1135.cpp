#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e2 + 10;
int a[maxn];
int ma[maxn][maxn];
int n, s, t;
int d[maxn], vis[maxn];
int main()
{
    cin >> n >> s >> t;
    memset(ma, 0x3f, sizeof ma);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i-a[i]>=1)
            ma[i][i - a[i]] = 1;
        if (i+a[i]<=n)
            ma[i][i + a[i]] = 1;
    }
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    for (int i = 1; i <=n;i++){
        int minx = maxn*maxn;
        int u = -1;
        for (int i = 1; i <= n;i++)
            if (!vis[i]&&d[i]<minx){
                u = i;
                minx = d[i];
            }
        if (u==-1)
            break;
        vis[u] = 1;
        for (int j = 1; j <= n;j++)
            if (!vis[j]&&d[j]>d[u]+ma[u][j])
                d[j] = d[u] + ma[u][j];
    }
    if (d[t] == 0x3f3f3f3f)
        cout << "-1";
    else
        cout << d[t];
    return 0;
}