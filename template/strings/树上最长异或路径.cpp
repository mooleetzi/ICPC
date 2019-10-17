#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct node
{
    int v, w, nxt;
} edge[maxn];
int head[maxn];
int cnt = -1;
void add(int u, int v, int w)
{
    edge[++cnt].nxt = head[u];
    edge[cnt].v = v;
    edge[cnt].w = w;
    head[u] = cnt;
}
int sum[maxn];
void dfs(int x, int fa)
{ //预处理
    for (int i = head[x]; ~i; i = edge[i].nxt)
    {
        int v = edge[i].v;
        int w = edge[i].w;
        if (v != fa)
        {
            sum[v] = sum[x] ^ w;
            dfs(v, x);
        }
    }
}
struct trie
{
    int ch[2];
} t[maxn];
int tot;
void build(int val, int x)
{
    for (int i = (1 << 30); i; i >>= 1)
    {
        bool c = val & i; //取出二进制下这个数的当前位置
        if (!t[x].ch[c])
        {
            t[x].ch[c] = ++tot;
        }
        x = t[x].ch[c];
    }
}
int query(int val, int x)
{
    int ans = 0;
    for (int i = (1 << 30); i; i >>= 1)
    {
        bool c = val & i;
        if (t[x].ch[!c])
        { //如果这一位可以进行异或就沿着这一条往下走
            ans += i;
            x = t[x].ch[!c];
        }
        else
            x = t[x].ch[c]; //否则就沿着另一条路往下走
    }
    return ans;
}
int main()
{
    memset(head, -1, sizeof(head));
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, -1); //预处理出每一个节点到根的异或和
    for (int i = 1; i <= n; ++i)
        build(sum[i], 0); //建立trie数
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, query(sum[i], 0)); //查询，取最大值
    }
    printf("%d\n", ans);
}