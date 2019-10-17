/*
    超级源点向每个猪圈连猪圈原始数量的边
    猪圈向每个有钥匙的人连inf边
    每个人向汇点连需求猪的数量边
    ！！！划重点
    每个猪圈按人来的先后顺序连边，以保证可以匀一些猪到下一个人
    如猪圈1先后x，y，z有钥匙，那么(x,y,inf),(y,z,inf)
    dinic:47ms
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
const int maxn = 1e4 + 3e2 + 50;
const int inf = 0x3f3f3f3f;
int n, m, s, t; //点数，边数，源点，汇点,涉及源点终点不传参直接再全局找
struct edge
{
    int v, nxt, w; //终点 下一条边节点 残余容量
} edg[20 * maxn];
int head[maxn], cnt; //记录边序号，注意从0开始，以便保持正边和反边的关系 z^1=f,f^1=z
int dep[maxn];       //记录分层图
int cur[maxn];       //当前弧优化
int pig[maxn];
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
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> m >> n)
    {
        init();
        memset(pig, 0, sizeof pig);
        for (int i = 1; i <= m; i++)
            p[i].clear();
        s = 0, t = m + n + 1;
        for (int i = 1; i <= m; i++)
            cin >> pig[i];
        for (int i = 1; i <= m; i++) //超级源点到猪圈建边
        {
            add(s, i, pig[i]);
            add(i, s, 0);
        }
        for (int i = 1; i <= n; i++)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int h;
                cin >> h;
                add(h, m + i, inf);
                add(m + i, h, 0);
                p[h].push_back(m + i);
            }
            int x;
            cin >> x;
            add(m + i, t, x);
            add(t, m + i, 0);
        }
        for (int i = 1; i <= m; i++)
        {
            int sz = p[i].size();
            for (int j = 1; j < sz; j++)
            {
                int pre = p[i][j - 1];
                int cur = p[i][j];
                add(pre, cur, inf);
                add(cur, pre, 0);
            }
        }
        cout << dinic() << "\n";
    }
    return 0;
}
