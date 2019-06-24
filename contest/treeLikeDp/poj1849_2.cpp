#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
struct edge
{
    int to, w;
    edge() {}
    edge(int y, int z)
    {
        to = y;
        w = z;
    }
};
vector<edge> g[maxn];
int n, s;
int dis1[maxn], dis2[maxn],ans;
void dfs(int u,int fa){
    for (int i = 0; i < g[u].size();i++){
        int v = g[u][i].to;
        int d = g[u][i].w;
        if (v==fa)
            continue;
        dfs(v, u);
        if (dis1[u]<dis1[v]+d){
            dis2[u] = dis1[u];
            dis1[u] = dis1[v] + d;
        }
        else if (dis2[u] < dis1[v] + d)
            dis2[u] = dis1[v] + d;
    }
    ans = max(ans, dis1[u] + dis2[u]);
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(edge(y, z));
        g[y].push_back(edge(x, z));
        sum += 2 * z;
    }
    dfs(s, -1);
    ans = sum - ans;
    cout << ans << "\n";
    return 0;
}
