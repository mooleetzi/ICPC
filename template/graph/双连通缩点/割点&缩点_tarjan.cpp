#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> g[10010];
int dfn[10010], low[10010], iscut[10010], son[10010];
int deep, root, n, m, ans;

int tarjan(int u, int fa)
{
    int child = 0, lowu;
    lowu = dfn[u] = ++deep;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = g[u][i];
        if (!dfn[v])
        {
            child++;
            int lowv = tarjan(v, u);
            lowu = min(lowu, lowv);
            if (lowv > dfn[u])
            {
                iscut[u] = 1;
            }
        }
        else
        {
            if (v != fa && dfn[v] < dfn[u])
            {
                lowu = min(lowu, dfn[v]);
            }
        }
    }
    if (fa < 0 && child == 1)
    {
        iscut[u] = false;
    }
    low[u] = lowu;
    return lowu;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int from, to;
        scanf("%d%d", &from, &to);
        g[from].push_back(to);
        g[to].push_back(from);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            root = i;
            tarjan(i, -1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (iscut[i])
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
    {
        if (iscut[i])
        {
            printf("%d ", i);
        }
    }
    return 0;
}