/*
    树直径 两次dfs解法
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
struct edge{
    int to, w;
    edge(){}
    edge(int y,int z){
        to = y;
        w = z;
    }
};
vector<edge> g[maxn];
int n, s;
int dis[maxn],node,maxx;
void dfs(int u,int fa){
    for (int i = 0; i < g[u].size();i++){
        int v = g[u][i].to;
        int d = g[u][i].w;
        if (v==fa)
            continue;
        dis[v] = dis[u] + d;
        dfs(v, u);
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    int sum = 0;
    for (int i = 0; i < n - 1;i++){
        int x, y,z;
        cin >> x >> y >> z;
        g[x].push_back(edge(y, z));
        g[y].push_back(edge(x, z));
        sum += 2 * z;
    }
    dfs(s, -1);
    memset(dis, 0, sizeof dis);
    node = max_element(dis + 1, dis + n + 1) - dis;
    dfs(node, -1);
    maxx = *max_element(dis + 1, dis + 1 + n);
    cout << sum-maxx << "\n";
    return 0;
}
