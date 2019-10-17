/*
    POJ_3694
    边双连通缩点+并查集维护lca
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
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 2e5 + 10;
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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
struct node
{
    int to, nxt;
} edg[maxn << 1];
int head[maxn], low[maxn], dfn[maxn], fa[maxn], dcc[maxn], vis[maxn], pre[maxn], deep[maxn], dcc_num, tot, cnt, bridge;
stack<int> st;
vector<int> g[maxn << 1];
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y)
        fa[y] = x;
}
void add(int x, int y)
{
    edg[tot].nxt = head[x];
    edg[tot].to = y;
    head[x] = tot++;
}
void tarjan(int u, int pre)
{
    dfn[u] = low[u] = ++cnt;
    st.push(u);
    for (int i = head[u]; ~i; i = edg[i].nxt)
    {
        int v = edg[i].to;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v]) //不能返祖则为桥
                ++bridge;
        }
        else if (v != pre)
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        ++dcc_num;
        while (!st.empty())
        {
            int temp = st.top();
            st.pop();
            dcc[temp] = dcc_num;
            if (temp == u)
                break;
        }
    }
}
void dfs(int u, int d)
{
    vis[u] = 1;
    deep[u] = d;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = g[u][i];
        if (!vis[v])
        {
            pre[v] = u;
            dfs(v, d + 1);
        }
    }
}

void init()
{
    tot = cnt = dcc_num = bridge = 0;
    memset(head, -1, sizeof(int) * (n + 1));
    memset(dfn, 0, sizeof(int) * (n + 1));
    memset(low, 0, sizeof(int) * (n + 1));
    memset(dcc, 0, sizeof(int) * (n + 1));
    memset(deep, 0, sizeof(int) * (n + 1));
    memset(vis, 0, sizeof(int) * (n + 1));
}
void join(int l, int r)
{
    l = find(dcc[l]), r = find(dcc[r]);
    while (l != r)
    {
        if (deep[l] > deep[r])
        {
            bridge--;
            fa[l] = find(pre[l]);
            l = fa[l];
        }
        else if (deep[l] < deep[r])
        {
            bridge--;
            fa[r] = find(pre[r]);
            r = fa[r];
        }
        else
        {
            bridge -= 2;
            fa[l] = find(pre[l]);
            fa[r] = find(pre[r]);
            l = fa[l];
            r = fa[r];
        }
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int cas = 1;
    while (~scanf("%d%d", &n, &m) && (n + m))
    {
        init();
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
        }
        tarjan(1, -1);
        for (int i = 1; i <= dcc_num; i++)
            g[i].clear(), fa[i] = i;
        for (int u = 1; u <= n; u++)
            for (int j = head[u]; ~j; j = edg[j].nxt)
            {
                int v = edg[j].to;
                if (dcc[u] != dcc[v])
                {
                    g[dcc[u]].push_back(dcc[v]);
                    g[dcc[v]].push_back(dcc[u]);
                }
            }
        dfs(1, 1); //建树
        int t;
        printf("Case %d:\n", cas++);
        scanf("%d", &t);
        while (t--)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            join(l, r);
            printf("%d\n", max(0, bridge));
        }
    }
    return 0;
}