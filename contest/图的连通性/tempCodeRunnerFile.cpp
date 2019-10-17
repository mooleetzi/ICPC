#include <bits/stdc++.h>
using namespace std;
const int N = 4e4 + 10;
struct P
{
    int next;
    int to, from, cost;
    int lca;
};
P edge[N << 1]; //树的链表
P qedge[501];   //需要查询LCA的两节点的链表
int n, m, p, x, y, rt;
int num_edge, num_qedge, head[N], qhead[N];
int father[N];
int visit[N]; //判断是否被找过
int dis[N], ind[N];
void add_edge(int from, int to, int w)
{ //建立树的链表
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    edge[num_edge].cost = w;
    head[from] = num_edge;
}
void add_qedge(int from, int to)
{ //建立需要查询LCA的两节点的链表
    qedge[++num_qedge].next = qhead[from];
    qedge[num_qedge].from = from;
    qedge[num_qedge].to = to;
    qhead[from] = num_qedge;
}
int find(int z)
{
    if (father[z] != z)
        father[z] = find(father[z]);
    return father[z];
}
void dfs(int x)
{
    father[x] = x;                             //由于节点x被看作是根节点，所以把x的father设为它自己
    visit[x] = 1;                              //标记为已被搜索过
    for (int k = head[x]; k; k = edge[k].next) //遍历所有与x相连的节点
        if (!visit[edge[k].to])
        {                           //若未被搜索
            dfs(edge[k].to);        //以该节点为根节点搞小树
            father[edge[k].to] = x; //把x的孩子节点的father重新设为x
        }
    for (int k = qhead[x]; k; k = qedge[k].next) //搜索包含节点x的所有询问
        if (visit[qedge[k].to])
        {                                     //如果另一节点已被搜索过
            qedge[k].lca = find(qedge[k].to); //把另一节点的祖先设为这两个节点的最近公共祖先
            if (k & 1)                        //由于将每一组查询变为两组，所以2n-1和2n的结果是一样的
                qedge[k + 1].lca = qedge[k].lca;
            else
                qedge[k - 1].lca = qedge[k].lca;
        }
}
void dijkstra(int u)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    while (!que.empty())
        que.pop();
    que.emplace(0, u);
    dis[u] = 0;
    while (!que.empty())
    {
        int u = que.top().second;
        int w = que.top().first;
        que.pop();
        if (dis[u] < w)
            continue;
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].cost;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                que.emplace(dis[v], v);
            }
        }
    }
}
void init()
{
    num_edge = num_qedge = 0;
    memset(head, -1, sizeof(int) * (n + 1));
    memset(qhead, -1, sizeof(int) * (n + 1));
    memset(visit, 0, sizeof(int) * (n + 1));
    memset(dis, 0x3f, sizeof(int) * (n + 1));
    memset(ind, 0, sizeof(int) * (n + 1));
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i < n; ++i)
        {
            int w;
            scanf("%d%d%d", &x, &y, &w); //输入每条边
            add_edge(x, y, w);
            add_edge(y, x, w);
            ind[y]++;
        }
        for (int i = 1; i <= n; i++)
            if (!ind[i])
            {
                rt = i;
                break;
            }
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &x, &y);
            add_qedge(x, y);
            add_qedge(y, x);
        }
        dfs(rt); //进入以p为根节点的树的深搜
        dijkstra(rt);
        for (int i = 1; i <= m; i++)
        {
            int u = qedge[i << 1].from;
            int v = qedge[i << 1].to;
            int mid = qedge[i << 1].lca;
            printf("%d\n", dis[u] + dis[v] - 2 * dis[mid]);
        }
    }
    return 0;
}