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
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;
int n, m, s, t, f, d; //点数，边数，源点，汇点,涉及源点终点不传参直接再全局找
struct edge
{
    int v, nxt, w; //终点 下一条边节点 残余容量
} edg[20 * maxn];
int head[maxn], cnt; //记录边序号，注意从0开始，以便保持正边和反边的关系 z^1=f,f^1=z
int dep[maxn];       //记录分层图
int cur[maxn];       //当前弧优化
vector<int> p[maxn];
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
void add_edge(int u, int v, int w)
{
    add(u, v, w);
    add(v, u, 0);
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
int vis[maxn][maxn];
inline int f1(int x)
{
    return n + x;
}
inline int f2(int x)
{
    return n + f + x;
}
inline int d1(int x)
{
    return n + 2 * f + x;
}
inline int d2(int x)
{
    return n + 2 * f + d + x;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> n >> f >> d;
    s = n + 2 * f + 2 * d + 1;
    t = s + 2;
    int st = s + 1;
    add_edge(s, st, n);
    for (int i = 1; i <= n; i++)
        add_edge(st, i, 1);
    for (int i = 1; i <= f; i++)
        add_edge(f1(i), f2(i), 1);
    for (int i = 1; i <= d; i++)
        add_edge(d1(i), d2(i), 1), add_edge(d2(i), t, 1);
    for (int i = 1; i <= n; i++)
    {
        vector<int> ff;
        ff.clear();
        int fn, dn;
        cin >> fn >> dn;
        for (int j = 0; j < fn; j++)
        {
            int x;
            cin >> x;
            ff.push_back(x);
            add_edge(i, f1(x), 1);
        }
        for (int j = 0; j < dn; j++)
        {
            int x;
            cin >> x;
            for (int k = 0; k < fn; k++)
                if (!vis[ff[k]][x])
                {
                    int fc = ff[k];
                    add_edge(f2(fc), d1(x), 1);
                    vis[fc][x] = 1;
                }
        }
    }
    cout << dinic() << "\n";
    return 0;
}
