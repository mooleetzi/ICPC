/*
    最短路建图跑最小割
*/
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, int> P;
int n, m, k;
const int maxn = 1e4 + 10;
const ll inf = 1e14;
template <class T>
inline T read()
{
    int f = 1;
    T ret = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = (ret << 1) + (ret << 3) + ch - '0';
        ch = getchar();
    }
    ret *= f;
    return ret;
}
template <class T>
inline void write(T n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        write(n / 10);
    }
    putchar(n % 10 + '0');
}
int s, t; //点数，边数，源点，汇点,涉及源点终点不传参直接再全局找
struct edge
{
    int v, nxt;
    ll w; //终点 下一条边节点 残余容量
} edg[maxn * 10];
int head[maxn], cnt; //记录边序号，注意从0开始，以便保持正边和反边的关系 z^1=f,f^1=z
int dep[maxn];       //记录分层图
int cur[maxn];       //当前弧优化
void init()
{
    cnt = 0;
    memset(head, -1, sizeof head);
}
void add(int u, int v, ll w)
{
    edg[cnt].v = v,
    edg[cnt].w = w; //初始残余容量为最大容量
    edg[cnt].nxt = head[u];
    head[u] = cnt++;
}
void add_edge(int u, int v, ll w)
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
ll dfs(int u, ll flow)
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
ll dinic()
{
    ll res = 0;
    while (bfs())
    {
        memcpy(cur, head, sizeof(head));
        res += dfs(s, inf); //源点流量无穷
    }
    return res;
}
vector<P> g[maxn], f[maxn];
ll d1[maxn], d2[maxn];
ll solve()
{
    priority_queue<P, vector<P>, greater<P>> que;
    while (!que.empty())
        que.pop();
    for (int i = 1; i <= n; i++)
        d1[i] = 1e14, d2[i] = 1e14;
    d1[1] = 0;
    d2[n] = 0;
    que.emplace(0, 1);
    while (!que.empty())
    {
        P tmp = que.top();
        que.pop();
        int u = tmp.second;
        if (d1[u] < tmp.first)
            continue;
        int sz = g[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = g[u][i].second;
            ll w = g[u][i].first;
            if (d1[v] > d1[u] + w)
            {
                d1[v] = d1[u] + w;
                que.emplace(d1[v], v);
            }
        }
    }
    que.emplace(0, n);
    while (!que.empty())
    {
        P tmp = que.top();
        que.pop();
        int u = tmp.second;
        if (d2[u] < tmp.first)
            continue;
        int sz = f[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = f[u][i].second;
            ll w = f[u][i].first;
            if (d2[v] > d2[u] + w)
            {
                d2[v] = d2[u] + w;
                que.emplace(d2[v], v);
            }
        }
    }
    init();
    for (int i = 1; i <= n; i++)
    {
        int sz = g[i].size();
        for (int j = 0; j < sz; j++)
        {
            int v = g[i][j].second;
            ll w = g[i][j].first;
            if (d1[i] + d2[v] + w == d1[n]) //最短路上的点
                add_edge(i, v, w);
        }
    }
    return dinic();
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T = read<int>();
    while (T--)
    {
        n = read<int>(), m = read<int>();
        s = 1, t = n;
        for (int i = 1; i <= n; i++)
            g[i].clear(), f[i].clear();
        for (int i = 0; i < m; i++)
        {
            int x = read<int>(), y = read<int>();
            ll c = read<ll>();
            g[x].emplace_back(c, y);
            f[y].emplace_back(c, x);
        }
        write(solve());
        puts("");
    }
    return 0;
}
