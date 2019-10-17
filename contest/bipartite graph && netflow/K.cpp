/*
    最小费用最大流
    注意源点到人的的容量也是1，如果设为inf则会一个人找好几次，谨记
    应该也阔以用最佳匹配km算法做，把路径长度的相反数设为边权
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
const int maxn = 1e2 + 10;
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
        // cout << t << ": " << dis[t] << "\n";
        memcpy(cur, head, sizeof(head));
        dfs(s, inf);
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
int main(int argc, char const *argv[])
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
        dinic();
        // cout << maxflow << " " << mincost << "\n";
        cout << mincost << "\n";
    }
    return 0;
}
