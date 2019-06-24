#include <iostream>
#include <vector>
using namespace std;
const int maxn = 6050;
int dp[maxn][2], fa[maxn];
int n;
vector<int> g[maxn];
void dfs(int u, int fa)
{
    dp[u][0] = 0;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += dp[v][0];
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            cin >> dp[i][1], g[i].clear(),fa[i]=0;
        int x, y;
        while (cin >> x >> y && x && y)
        {
            fa[x] = y;
            g[y].push_back(x);
        }
        int rt;
        for (int i = 1; i <= n; i++)
            if (!fa[i])
                rt = i;
        dfs(rt, -1);
        cout << max(dp[rt][0], dp[rt][1]) << "\n";
    }
    return 0;
}
