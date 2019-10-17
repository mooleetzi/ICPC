/*
    二分+最大流
    floyed求解最短路
    要求最长路最短，则二分答案
    每次将小于mid值的边（跑完floyed之后）加入图中，判断最大流是否为c
    如果是，则将上界下调，记录答案
    否则更新下界
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
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int maxV = 1e4 + 10;
const int maxE = 5e4 + 10;
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 3e2 + 50;
int a[maxn][maxn];
int n, m, s, t, k, c; //点数，边数，源点，汇点,涉及源点终点不传参直接再全局找
struct edge
{
    int v, nxt, w; //终点 下一条边节点 残余容量
} edg[20 * maxn];
int head[maxn], cnt; //记录边序号，注意从0开始，以便保持正边和反边的关系 z^1=f,f^1=z
int dep[maxn];       //记录分层图
int cur[maxn];       //当前弧优化
void init()
{
    cnt = 0;
    memset(head, -1, sizeof head);
}
void add(int u, int v, int w)
{
    edg[cnt].v = v,
    edg[cnt].w = w; //初始残余容量为最大容量
    edg[cnt].nxt = head[u];
    head[u] = cnt++;
}
void add_edge(int u, int v, int w)
{
    add(u, v, w);
    add(v, u, 0);
}
bool bfs()
{
    queue<int> que;
    while (!que.empty())
        que.pop();
    memset(dep, -1, sizeof dep);
    que.push(s);
    dep[s] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int i = head[u]; ~i; i = edg[i].nxt)
        {
            int v = edg[i].v;
            if (dep[v] == -1 && edg[i].w)
            {
                dep[v] = dep[u] + 1;
                que.push(v);
            }
        }
    }
    return dep[t] != -1;
}
int dfs(int u, int flow)
{
    if (u == t || !flow)
        return flow;
    int res = 0;
    for (int i = cur[u]; ~i; i = edg[i].nxt)
    {
        cur[u] = i;
        int v = edg[i].v;
        if (dep[v] == dep[u] + 1 && edg[i].w)
        {
            int fl = dfs(v, min(flow, edg[i].w));
            if (fl)
            {
                edg[i].w -= fl;
                edg[i ^ 1].w += fl;
                res += fl;
                flow -= fl;
                if (!flow) //这条边的残余流量为0，不可能再增广
                    break;
            }
        }
    }
    if (!res)
        dep[u] = -1; //当前点没有增广路，下一次没必要再跑这条边，炸点优化
    return res;
}
int dinic()
{
    int res = 0;
    while (bfs())
    {
        memcpy(cur, head, sizeof(head));
        res += dfs(s, inf); //源点流量无穷
    }
    return res;
}
void debug()
{
    for (int i = 1; i <= t; i++)
    {
        cout << i << " :\n";
        for (int j = head[i]; ~j; j = edg[j].nxt)
            cout << edg[j].v << " " << edg[j].w << " \n";
    }
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
    while (cin >> k >> c >> m)
    {
        s = k + c + 1;
        t = s + 1;
        for (int i = 1; i <= k + c; i++)
            for (int j = 1; j <= k + c; j++)
            {
                cin >> a[i][j];
                if (i != j && !a[i][j])
                    a[i][j] = inf;
            }
        for (int p = 1; p <= k + c; p++)
            for (int i = 1; i <= k + c; i++)
                for (int j = 1; j <= k + c; j++)
                    a[i][j] = min(a[i][p] + a[p][j], a[i][j]);
        int l = 0, r = 200 * (k + c);
        int ans = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            init();
            for (int i = 1; i <= k + c; i++)
                if (i <= k)
                    add_edge(i, t, m);
                else
                    add_edge(s, i, 1);
            for (int i = k + 1; i <= k + c; i++)
                for (int j = 1; j <= k; j++)
                    if (a[i][j] <= mid)
                        add_edge(i, j, 1);
            int cur = dinic();
            // cout << cur << "\n";
            if (cur == c)
            {
                r = mid - 1;
                ans = mid;
            }
            else
                l = mid + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}