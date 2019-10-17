/*
    tarjan边双连通缩点
    并查集维护叶子节点m
    res=(m+1)>>1
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
int dfn[maxn], low[maxn], dcc[maxn], head[maxn], outd[maxn], ind[maxn], fa[maxn], dcc_num, cnt, tot, bridge;
struct node
{
    int to, nxt;
} edg[maxn << 1];
stack<int> st;
int find(int u)
{
    if (fa[u] == u)
        return u;
    return fa[u] = find(fa[u]);
}
void add(int x, int y)
{
    edg[tot].to = y;
    edg[tot].nxt = head[x];
    head[x] = tot++;
}
void tarjan(int u, int p)
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
            if (dfn[u] < low[v])
                ++bridge;
        }
        else if (v != p)
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
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), m = read<int>();
    memset(head, -1, sizeof(int) * (n + 1));
    for (int i = 0; i < m; i++)
    {
        int x = read<int>(), y = read<int>();
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, -1);
    for (int i = 1; i <= dcc_num; i++)
        fa[i] = i;
    for (int u = 1; u <= n; ++u)
        for (int j = head[u]; ~j; j = edg[j].nxt)
        {
            int v = edg[j].to;
            int x = find(dcc[u]), y = find(dcc[v]);
            if (x != y)
            {
                ++ind[dcc[u]];
                ++ind[dcc[v]];
                fa[y] = x;
            }
        }
    int res = 0;
    for (int i = 1; i <= dcc_num; i++)
        if (ind[i] == 1)
            ++res;
    writeln((res + 1) >> 1);
    return 0;
}