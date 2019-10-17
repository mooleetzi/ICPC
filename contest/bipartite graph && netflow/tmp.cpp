#pragma GCC optimize(2)
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define P pair<int, int>
using namespace std;
const int maxn = 6060;
const int inf = 0x3f3f3f3f;
using namespace std;
struct edge
{
    int to, cap, cost, rev;
};
int n, m, maxflow, s, t, mincost, h[maxn];
vector<edge> G[maxn];
int dist[maxn], prevv[maxn], preve[maxn]; // 前驱节点和对应边
inline void init()
{
    for (int i = 1; i <= maxn; i++)
        G[i].clear();
}
inline void add_edge(int from, int to, int cap, int cost)
{
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
} // 在vector 之中找到边的位置所在!
inline void min_cost_flow(int f)
{
    memset(h, 0, sizeof(h));
    while (f > 0)
    {
        priority_queue<P, vector<P>, greater<P>> D;
        memset(dist, inf, sizeof dist);
        dist[s] = 0;
        D.push(P(0, s));
        while (!D.empty())
        {
            P now = D.top();
            D.pop();
            if (dist[now.second] < now.first)
                continue;
            int v = now.second;
            for (int i = 0; i < (int)G[v].size(); ++i)
            {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
                {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    D.push(P(dist[e.to], e.to));
                }
            }
        }
        // 无法增广 ， 就是找到了答案了！
        if (dist[t] == inf)
            break;
        for (int i = 1; i <= n; ++i)
            h[i] += dist[i];
        int d = f;
        for (int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        maxflow += d;
        mincost += d * h[t];
        for (int v = t; v != s; v = prevv[v])
        {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
}
struct node
{
    int x, y, idx;
};
inline int getDis(node a, node b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}
char ss[maxn][maxn];
vector<node> H, M;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m && (n + m))
    {
        H.clear(), M.clear();
        init();
        for (int i = 0; i < n; i++)
            cin >> ss[i];
        int item = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (ss[i][j] != '.')
                {
                    node cur;
                    cur.x = i, cur.y = j, cur.idx = ++item;
                    if (ss[i][j] == 'H')
                        H.push_back(cur);
                    else
                        M.push_back(cur);
                }
        s = item + 1, t = item + 2;
        // cout << item << " " << s << " " << t << "\n";
        int hsz = H.size();
        int msz = M.size();
        for (int i = 0; i < msz; i++)
        {
            add_edge(s, M[i].idx, 1, 0);
            for (int j = 0; j < hsz; j++)
            {
                add_edge(M[i].idx, H[j].idx, 1, getDis(M[i], H[j]));
            }
        }
        for (int j = 0; j < hsz; j++)
            add_edge(H[j].idx, t, 1, 0);
        min_cost_flow(inf);
        cout << mincost << "\n";
    }
    return 0;
}