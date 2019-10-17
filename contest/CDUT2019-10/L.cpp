/*
    最大费用最大流
    拆点建图
 */
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
const int maxV = 1e4 + 10;
const int maxE = 5e4 + 10;
const int inf = 0x3f3f3f3f;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
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
struct node
{
    int s, t, c, op, idx;
    bool operator<(const node &x) const
    {
        return t < x.t;
    }
} v[maxV];

int n, m, s, t; //点 边 源点 汇点
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
    cnt = 0;
    memset(head, -1, sizeof head);
    memset(inq, 0, sizeof inq);
    maxflow = mincost = 0;
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
        memcpy(cur, head, sizeof head);
        dfs(s, inf);
    }
}
inline int left(int x)
{
    return x;
}
inline int right(int x)
{
    return x + m;
}
void debug()
{
    for (int i = 1; i <= 2 * m + 3; i++)
    {
        cout << i << ": ";
        for (int j = head[i]; ~j; j = edg[j].nxt)
        {
            cout << edg[j].v << " " << edg[j].w << " " << edg[j].c << "; ";
        }
        cout << "\n";
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int z;
    read(z);
    while (z--)
    {
        init();
        int k, w;
        read(n), read(m), read(k), read(w);
        s = 2 * m + 1;
        int pt = 2 * m + 2;
        t = 2 * m + 3;
        for (int i = 1; i <= m; i++)
        {
            read(v[i].s), read(v[i].t), read(v[i].c), read(v[i].op);
            v[i].idx = i;
            add_edge(s, left(i), inf, 0);
            add_edge(left(i), right(i), 1, 0);
            add_edge(right(i), pt, 1, -v[i].c);
        }
        sort(v + 1, v + m + 1);
        for (int i = 1; i < m; i++)
            for (int j = i + 1; j <= m; j++)
            {
                if (v[j].s >= v[i].t)
                {
                    int f = v[i].op == v[j].op;
                    int p = v[i].idx, q = v[j].idx;
                    add_edge(right(p), left(q), 1, f * w - v[i].c);
                }
            }
        add_edge(pt, t, k, 0);
        dinic();
        write(-mincost);
        puts("");
    }
    return 0;
}
