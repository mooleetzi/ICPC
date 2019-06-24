#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
vector<int> g[maxn];
int deg[maxn],vis[maxn],dis[maxn];
using pa=pair<int, int>;
int n, m;
int fa[maxn];
int find(int x)
{
    if (fa[x]!=x)
        return fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    int xx = find(x);
    int yy = find(y);
    fa[yy] = xx;
}
void bfs(int now){
    queue<int> que;
    que.push(now);
    int num = 0;
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for (int i = 0; i < g[cur].size(); i++)
        {
            int to = g[cur][i];
            if (find(cur)!=find(to)){
                ++num;
                cout << cur << " " << to << "\n";
                merge(cur, to);
                que.push(to);
            }
            if (num==n-1)
                return;
        }
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n>>m;
    for (int i = 1; i <= n;i++)
        fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        ++deg[x];
        ++deg[y];
    }
    int s, maxx = -1;
    for (int i = 1; i <= n;i++){
        if (deg[i]>maxx){
            maxx = deg[i];
            s = i;
        }
    }
        bfs(s);
    return 0;
}

