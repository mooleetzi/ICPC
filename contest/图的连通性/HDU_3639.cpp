/*
    缩点建反图，入度为0点开始dfs，记录最大值
    注意只有一个强连通时的情况以及需要加上自己的那个环的数目-1
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
const int maxn = 1e5 + 10;
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
} edg[maxn];
int head[maxn], low[maxn], dfn[maxn], scc[maxn], num[maxn], ind[maxn], vis[maxn], res[maxn], cnt, tot, scc_num, maxx, f, tmp;
stack<int> st;
vector<P> g[maxn];
unordered_set<int> sc;
void init()
{
    cnt = tot = scc_num = maxx = f = 0;
    memset(head, -1, sizeof(int) * (n + 1));
    memset(low, 0, sizeof(int) * (n + 1));
    memset(dfn, 0, sizeof(int) * (n + 1));
    memset(scc, 0, sizeof(int) * (n + 1));
    memset(num, 0, sizeof(int) * (n + 1));
    memset(ind, 0, sizeof(int) * (n + 1));
    for (int i = 0; i < n; i++)
        g[i].clear();
    while (!st.empty())
        st.pop();
    sc.clear();
}
void add(int x, int y)
{
    edg[tot].nxt = head[x];
    edg[tot].to = y;
    head[x] = tot++;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++cnt;
    st.push(u);
    for (int i = head[u]; ~i; i = edg[i].nxt)
    {
        int v = edg[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!scc[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        ++scc_num;
        int cur = 0;
        while (!st.empty())
        {
            int temp = st.top();
            st.pop();
            scc[temp] = scc_num;
            ++cur;
            if (temp == u)
                break;
        }
        num[scc_num] = cur;
    }
}
void dfs(int u)
{
    int sz = g[u].size();
    vis[u] = 1;
    for (int i = 0; i < sz; i++)
    {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if (!vis[v])
        {
            tmp += w;
            dfs(v);
        }
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
        }
        for (int i = 0; i < n; i++)
            if (!dfn[i])
                tarjan(i);
        for (int u = 0; u < n; u++)
            for (int j = head[u]; ~j; j = edg[j].nxt)
            {
                int v = edg[j].to;
                if (scc[u] != scc[v])
                {
                    g[scc[v]].emplace_back(scc[u], num[scc[u]]);
                    ind[scc[u]]++;
                }
            }
        for (int i = 1; i <= scc_num; i++)
        {
            if (!ind[i])
            {
                memset(vis, 0, sizeof(int) * (scc_num + 2));
                tmp = num[i] - 1;
                dfs(i);
                if (tmp > maxx)
                {
                    maxx = tmp;
                    sc.clear();
                    sc.emplace(i);
                }
                else if (tmp == maxx)
                    sc.emplace(i);
            }
        }
        if (scc_num == 1)
        {
            printf("Case %d: %d\n", cas, n - 1);
            for (int i = 0; i < n - 1; i++)
                printf("%d ", i);
            printf("%d\n", n - 1);
            continue;
        }
        printf("Case %d: %d\n", cas, maxx);
        int r = 0;
        for (int i = 0; i < n; i++)
            if (sc.count(scc[i]))
                res[r++] = i;
        for (int i = 0; i < r - 1; i++)
            printf("%d ", res[i]);
        printf("%d\n", res[r - 1]);
    }
    return 0;
}