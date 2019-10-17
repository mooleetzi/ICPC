/*
    边双连通缩点后为一棵树
    有结论:n个点的一棵树，叶子节点的数目为m,要将其变为边双连通需要加(m+1)/2条边
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 100010;
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2];
int dfn[SIZE], low[SIZE], c[SIZE];
int n, m, tot, num, dcc, tc;
bool bridge[SIZE * 2];
int hc[SIZE], vc[SIZE * 2], nc[SIZE * 2];

void add(int x, int y)
{
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void add_c(int x, int y)
{
    vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
}

void tarjan(int x, int in_edge)
{
    dfn[x] = low[x] = ++num;
    for (int i = head[x]; i; i = Next[i])
    {
        int y = ver[i];
        //当前点未走过
        if (!dfn[y])
        {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x])
                //i 与 i^1是桥
                bridge[i] = bridge[i ^ 1] = true;
        }
        //反向边更新
        else if (i != (in_edge ^ 1))
            low[x] = min(low[x], dfn[y]);
    }
}

void dfs(int x)
{
    c[x] = dcc;
    for (int i = head[x]; i; i = Next[i])
    {
        int y = ver[i];
        if (c[y] || bridge[i])
            continue;
        dfs(y);
    }
}
int ind[SIZE], fa[SIZE];
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        fa[y] = x;
}
int main()
{
    scanf("%d%d", &n, &m);
    tot = 1;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, 0);
    for (int i = 1; i <= n; i++)
        if (!c[i])
        {
            ++dcc;
            dfs(i);
        }
    //缩点
    tc = 1;
    for (int i = 1; i <= dcc; i++)
        fa[i] = i;
    for (int i = 2; i <= tot; i++)
    {
        int x = ver[i ^ 1], y = ver[i];
        int u = find(c[x]), v = find(c[y]);
        if (u == v)
            continue;
        ++ind[c[x]];
        ++ind[c[y]];
        fa[v] = u;
    }
    int res = 0;
    for (int i = 1; i <= dcc; i++)
        if (ind[i] == 1)
            ++res;
    printf("%d", (res + 1) >> 1);
    return 0;
}