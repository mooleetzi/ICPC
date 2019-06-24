#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e4 + 10;
vector<int> g[maxn];
int sum[maxn], dp[maxn];
int n, ans, s = 1e9;
void dfs(int u, int fa)
{
    sum[u] = 1;
    int p = 0;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (v == fa)
            continue;
        dfs(v, u);
        sum[u] += sum[v];
        p = max(sum[v], p);
    }
    dp[u] = max(n - sum[u], p);
    if (dp[u] < s)
    {
        s = dp[u];
        ans = u;
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i <= n; i++)
            g[i].clear(), dp[i] = 0, sum[i] = 0;
        s = 1e9;
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1, 0);
        cout << ans << " " << s << "\n";
    }
    return 0;
}
