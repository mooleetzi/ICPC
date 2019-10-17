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
int head[maxNode], revHead[maxNode];
int dis[maxNode], inq[maxNode];
int n, m, k, s, t;
void spfa(int st, int en)
{
    memset(dis, 0x3f, sizeof dis);
    memset(inq, 0, sizeof inq);
    inq[en] = 1;
    dis[en] = 0;
    queue<int> que;
    while (!que.empty())
        que.pop();
    que.push(en);
    while (!que.empty())
    {
        int now = que.front();
        inq[now] = 0;
        que.pop();
        for (int i = revHead[now]; ~i; i = revEdge[i].next)
        {
            int v = revEdge[i].to;
            if (dis[now] + revEdge[i].w < dis[v])
            {
                dis[v] = dis[now] + revEdge[i].w;
                if (!inq[v])
                {
                    que.push(v);
                    inq[v] = 1;
                }
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
        spfa(s, t);
        int ans = aStar(s, t, k);
        cout << ans << "\n";
        return 0;
    }
