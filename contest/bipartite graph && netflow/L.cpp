/*
    将n个商店的k种物品需求拆成n*k个点
    将m个供应商的k种物品供应拆成m*k个点
    源点与n*k个点建立容量为需求，费用为0的边
    汇点与m*k个点建立容量为供应值，费用为0的边
    n*k与m*k按对应关系建立容量为需求，费用为对应的边
    跑最小费用最大流
*/
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
int n, m, k, s, t;
const int maxn = 1e2 + 52;
const int maxV = 1e4 + 10;
const int maxE = 5e4 + 10;
const int inf = 0x3f3f3f3f;
int cnt, maxflow, mincost;
struct edge
{
    int v, nxt, w, c; //终点，下一边序号，残余容量，单位流量费用
} edg[maxE * 2];
int head[maxV], cur[maxV]; //第一条边序号，下一次访问的边序号（用于当前弧优化）
int dis[maxV];             //分层图，类似最大流的dep数组
int inq[maxV];             //spfa记录
void init()
{
    cnt = mincost = maxflow = 0;
    memset(head, -1, sizeof head);
}
void add(int u, int v, int w, int c)
{
    edg[cnt].v = v;
    edg[cnt].w = w;
    edg[cnt].c = c;
    edg[cnt].nxt = head[u];
    head[u] = cnt++;
}
void add_edge(int u, int v, int w, int c)
{
    // cout << u << " " << v << "\n";
    // cout << c << "\n";
    add(u, v, w, c);
    add(v, u, 0, -c);
}
bool spfa()
{
    queue<int> que;
    while (!que.empty())
        que.pop();
    que.push(s);
    memset(dis, 0x3f, sizeof dis); //注意初始化，防止tle
    dis[s] = 0;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        inq[u] = 0;
        for (int i = head[u]; ~i; i = edg[i].nxt)
        {
            int v = edg[i].v;
            if (edg[i].w && dis[u] + edg[i].c < dis[v]) //还有残余容量且费用可以更新
            {
                dis[v] = dis[u] + edg[i].c;
                if (!inq[v])
                {
                    que.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    return dis[t] != inf;
}
int dfs(int u, int flow)
{
    if (u == t) //到达汇点
    {
        maxflow += flow;
        return flow;
    }
    int res = 0;
    inq[u] = 1;
    for (int i = cur[u]; ~i; i = edg[i].nxt)
    {
        int v = edg[i].v;
        if (!inq[v] && edg[i].w && dis[v] == dis[u] + edg[i].c) //没在队列，还有残余容量，满足费用分层图
        {
            cur[u] = i; //当前弧优化
            int fl = dfs(v, min(flow - res, edg[i].w));
            res += fl;
            edg[i ^ 1].w += fl;
            edg[i].w -= fl;
            mincost += fl * edg[i].c;
            if (res == flow)
                break;
        }
    }
    inq[u] = 0;
    return res;
}
void dinic()
{
    while (spfa())
    {
        memcpy(cur, head, sizeof(head));
        dfs(s, inf);
    }
}
int need[maxn][maxn], suply[maxn][maxn], good[maxn][maxn][maxn];
/*
    超级源s=0
    商店1~n*k
    每家商店的每种物品n*k+1~n*k+m*k
    超级汇t=(n+m)*k+1
*/
inline int sd(int p, int x)
{
    return (p - 1) * k + x;
}
inline int gd(int p, int x)
{
    return n * k + (p - 1) * k + x;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m >> k && (n + m + k))
    {
        init();
        memset(good, -1, sizeof good);
        s = 0, t = (n + m) * k + 1;
        int aneed = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                cin >> need[i][j];
                aneed += need[i][j];
                add_edge(s, sd(i, j), need[i][j], 0);
            }
        }
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= k; j++)
                cin >> suply[i][j];
        for (int i = 1; i <= k; i++)
            for (int j = 1; j <= n; j++)
                for (int p = 1; p <= m; p++)
                    cin >> good[i][j][p];
        // for (int i = 1; i <= n; i++)
        //     add_edge(s, i, inf, 0); //源点与商店相连，容量为inf，费用为0
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= k; j++)
            {
                int g = gd(i, j);
                add_edge(g, t, suply[i][j], 0);
            }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
                if (need[i][j])
                    for (int p = 1; p <= m; p++)
                    {
                        int cost = good[j][i][p];
                        int g = gd(p, j); //p供应商的j货物的点
                        int s = sd(i, j);
                        add_edge(s, g, need[i][j], cost);
                    }
        }
        dinic();
        // cout << "need: " << aneed << ", maxflow: " << maxflow << ", mincost: " << mincost << "\n";
        if (maxflow == aneed)
            cout << mincost << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}