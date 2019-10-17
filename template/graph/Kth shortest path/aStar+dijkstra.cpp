#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
const int maxNode = 1e3 + 10;
const int maxEdge = 1e6 + 10;
struct node
{
    int to, next, w;
} edge[maxEdge], revEdge[maxEdge];
struct op
{
    int u, h, g;
    op() {}
    op(int a, int b, int c)
    {
        u = a, h = b, g = c;
    }
    int operator<(const op &a) const
    {
        return h + g > a.h + a.g;
    }
};
struct dd
{
    int u, dis;
    dd() {}
    dd(int a, int b)
    {
        u = a, dis = b;
    }
    int operator<(const dd &a) const
    {
        return dis > a.dis;
    }
};
int head[maxNode], revHead[maxNode];
int dis[maxNode], inq[maxNode];
int n, m, k, s, t;
void dijkstra(int st, int en)
{
    memset(inq, 0, sizeof inq);
    memset(dis, 0x3f, sizeof dis);
    dis[en] = 0;
    priority_queue<dd> que;
    while (!que.empty())
        que.pop();
    que.push(dd(en, 0));
    while (!que.empty())
    {
        dd now = que.top();
        que.pop();
        if (inq[now.u])
            continue;
        inq[now.u] = 1;
        for (int i = revHead[now.u]; ~i; i = revEdge[i].next)
        {
            int v = revEdge[i].to;
            if (!inq[v] && dis[v] > dis[now.u] + revEdge[i].w)
            {
                dis[v] = dis[now.u] + revEdge[i].w;
                que.push(dd(v, dis[v]));
            }
        }
    }
}
int aStar(int st, int en, int k)
{
    int cnt = 0;
    if (st == en)
        ++k;
    if (dis[st] == inf)
        return -1;
    priority_queue<op> que;
    while (!que.empty())
        que.pop();
    que.push(op(st, dis[st], 0));
    while (!que.empty())
    {
        op now = que.top();
        que.pop();
        if (now.u == en)
            ++cnt;
        if (cnt == k)
            return now.g;
        for (int i = head[now.u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            op next;
            next.u = v;
            next.g = now.g + edge[i].w;
            next.h = dis[next.u];
            que.push(next);
        }
    }
    return -1;
}
void add(int a, int b, int c)
{
    static int tot = 0;
    edge[tot].to = b;
    edge[tot].next = head[a];
    edge[tot].w = c;
    head[a] = tot;
    revEdge[tot].to = a;
    revEdge[tot].next = revHead[b];
    revEdge[tot].w = c;
    revHead[b] = tot++;
}
int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        memset(head, -1, sizeof head);
        memset(revHead, -1, sizeof revHead);
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            add(x, y, z);
        }
        cin >> s >> t >> k;
        dijkstra(s, t);
        int ans = aStar(s, t, k);
        cout << ans << "\n";
    }
    return 0;
}
