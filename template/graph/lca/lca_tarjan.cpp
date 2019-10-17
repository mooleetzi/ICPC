/*
    洛谷p3379
    tarjan离线lca模板
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
const int N = 5e5 + 10;
struct P
{
    int next;
    int to;
    int lca;
};
P edge[N << 1];  //树的链表
P qedge[N << 1]; //需要查询LCA的两节点的链表
int n, m, p, x, y;
int num_edge, num_qedge, head[N], qhead[N];
int father[N];
int visit[N]; //判断是否被找过
void add_edge(int from, int to)
{ //建立树的链表
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
}
void add_qedge(int from, int to)
{ //建立需要查询LCA的两节点的链表
    qedge[++num_qedge].next = qhead[from];
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
void init()
{
    num_edge = num_qedge = 0;
    memset(head, 0, sizeof(int) * (n + 1));
    memset(qhead, 0, sizeof(int) * (n + 1));
    // memset(vis, 0, sizeof vis);
}
int main()
{
    scanf("%d%d%d", &n, &m, &p); //输入节点数，查询数和根节点
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &x, &y); //输入每条边
        add_edge(x, y);
        add_edge(y, x);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x, &y); //输入每次查询，考虑(u,v)时若查找到u但v未被查找，所以将(u,v)(v,u)全部记录
        add_qedge(x, y);
        add_qedge(y, x);
    }
    dfs(p); //进入以p为根节点的树的深搜
    for (int i = 1; i <= m; i++)
        printf("%d\n", qedge[i << 1].lca); //两者结果一样，只输出一组即可
    return 0;
}