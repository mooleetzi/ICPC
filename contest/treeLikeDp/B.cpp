#include <bits/stdc++.h>
using namespace std;
using pa = pair<int, int>;
const int maxn = 1e4 + 10;
vector<pa> g[maxn];
int n;
int dp[maxn][3],l[maxn];
void dfs(int u,int fa){
    int pre = 0, lu=-1;
    for (int i = 0; i < g[u].size();i++){
        int v = g[u][i].first;
        int w = g[u][i].second;
        dfs(v,u);
        if (dp[u][0]<dp[v][0]+w){
            dp[u][1] = dp[u][0];
            dp[u][0] = dp[v][0] + w;
            l[u] = v;
        }
        else if (dp[u][1]<dp[v][0]+w)
            dp[u][1] = dp[v][0] + w;
    }
}
void dfs(int u){
    for (int i = 0; i < g[u].size();i++){
        int v = g[u][i].first;
        int w = g[u][i].second;
        if (v==l[u])
            dp[v][2] = max(dp[u][1],dp[u][2]) + w;
        else
            dp[v][2] = max(dp[u][2],dp[u][0]) + w;
        dfs(v);
    }
}
int main(int argc, char const *argv[])  
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    while (cin >> n)
    {
        for (int i = 0; i <= n; i++)
            g[i].clear(), dp[i][0] = dp[i][1] = dp[i][2] = 0;
        for (int i = 2; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(pa(i, y));
        }
        dfs(1,0);
        dfs(1);
        for (int i = 1; i <= n; i++)
            cout << max(dp[i][0],dp[i][2]) << "\n";
    }
    return 0;
}
