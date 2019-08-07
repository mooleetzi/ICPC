/*
    dinic最大流（当前弧+炸点）
    加边前先init()
 */
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
const int maxn = 1e5 + 10;
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
int n, m, s, t; //点数，边数，源点，汇点,涉及源点终点不传参直接再全局找
struct edge
{
    int v, nxt, w; //终点 下一条边节点 残余容量
} edg[maxn * 10];
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
int main(int argc, char const *argv[])
{
    init();
    read(n), read(m), read(s), read(t);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        read(x), read(y), read(z);
        add(x, y, z);
        add(y, x, 0); //反边
    }
    write(dinic());
    return 0;
}
