/*
    最小费用最大流dinic
    使用前注意最大顶点和边
    init()
 */
#include <bits/stdc++.h>
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
int n, m, s, t; //点 边 源点 汇点
int cnt, maxflow, mincost;
struct edge
{
    int v, nxt, w, c; //终点，下一边序号，残余容量，单位流量费用
} edg[maxE * 2];
struct node
{
    int fa, idx; //增广路上连接的父节点及该边编号
} pre[maxV];
int head[maxV], cur[maxV]; //第一条边序号，下一次访问的边序号（用于当前弧优化）
int dis[maxV];             //分层图，类似最大流的dep数组
int inq[maxV];             //spfa记录
void init()
{
    cnt = 0;
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
    add(u, v, w, c);
    add(v, u, 0, -c);
}
bool spfa()
{
    queue<int> que;
    while (!que.empty())
        que.pop();
    que.push(s);
    memset(dis, 0x3f, sizeof(int) * (n + 2)); //注意初始化，防止tle
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
        memcpy(cur, head, sizeof(int) * (n + 2));
        dfs(s, inf);
    }
}
int main(int argc, char const *argv[])
{
    init();
    read(n), read(m), read(s), read(t);
    for (int i = 0; i < m; i++)
    {
        int x, y, w, c;
        read(x), read(y), read(w), read(c);
        add(x, y, w, c);
        add(y, x, 0, -c);
    }
    dinic();
    write(maxflow);
    putchar(' ');
    write(mincost);
    return 0;
}
