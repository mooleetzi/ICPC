#include<bits/stdc++.h>
using namespace std;
const int maxn = 160;
vector<int> g[maxn];
int dp[maxn][maxn],fa[maxn];
int n, p;
void dfs(int u,int fa){
    for (int i = 0; i < g[u].size();i++){
        int v = g[u][i];
        if (v==fa)
            continue;
        dfs(v, u);
        for (int j = p; j >= 2;j--){
            for (int k = 1; k < j;k++)
                dp[u][j] = min(dp[u][j], dp[u][j - k] + dp[v][k] - 1);
        }   
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p;
    for (int i = 0; i < n-1;i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        fa[y] = x;
    }
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n;i++)
        dp[i][1] = g[i].size();
    int rt=1;
    dfs(rt, -1);
    int ans = dp[rt][p];
    for (int i = 1; i <= n;i++)
        ans = min(ans, dp[i][p] + 1);//断掉与父节点的边
    cout << ans << "\n";
    return 0;
}
