#include <bits/stdc++.h>
using namespace std;
const int maxn = 220;
int n, m, t;
int dp[maxn][maxn];
int M[maxn], T[maxn], vis[maxn];
int ans;
double s;
void dfs(int i, int cnt, int m, int t)
{
    if (!m||!t){
        ans = max(cnt, ans);
        return;
    }
    // if ((clock()-s)/CLOCKS_PER_SEC>5)
    //     return;
    vis[i] = 1;
    for (int j = 1;j<=n;j++)
        if (!vis[j]&&m-M[j]>=0&&t-T[i]>=0)
            dfs(j, cnt + 1, m - M[j], t - T[j]);
    vis[i] = 0;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
        cin >> M[i] >> T[i];
    s = clock();
    for (int i = 1; i <= n; i++)
    {   
        dfs(i, 1, m - M[i], t - T[i]);
        for (int j = 1; j <= n;j++)
            vis[j] = 0;
    }
    cout << ans;
    return 0;
}
