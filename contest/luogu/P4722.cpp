#pragma optmize(3)
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
ll n, m, k;
const int maxn = 510;
const int mod = 998244353;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
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
struct node
{
    int u, v, cap, next;
} e[maxn * 10];
int n, m, s, t;
int cnt, head[maxn];
int d[maxn];
void init()
{
    cnt = 0;
    Fill(head, -1);
}

void add(int u, int v, int c)
{
    e[cnt] = node{u, v, c, head[u]};
    head[u] = cnt++;
}

void AddEdge(int u, int v, int c)
{
    add(u, v, c);
    add(v, u, 0);
}

int BFS()
{
    queue<int> q;
    Fill(d, -1);
    d[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = e[i].next)
        {
            int to = e[i].v;
            if (d[to] == -1 && e[i].cap > 0)
            {
                d[to] = d[u] + 1;
                q.push(to);
            }
        }
    }
    return d[t] != -1;
}

int dfs(int u, int a)
{
    int r = 0;
    if (u == t)
        return a;
    for (int i = head[u]; ~i && r < a; i = e[i].next)
    {
        int to = e[i].v;
        if (e[i].cap > 0 && d[to] == d[u] + 1)
        {
            int x = min(e[i].cap, a - r);
            x = dfs(to, x);
            r += x;
            e[i].cap -= x;
            e[i ^ 1].cap += x;
        }
    }
    if (!r)
        d[u] = -2;
    return r;
}

int Dinic()
{
    int maxflow = 0, t;
    while (BFS())
    {
        while (t = dfs(s, inf))
            maxflow += t;
    }
    return maxflow;
}