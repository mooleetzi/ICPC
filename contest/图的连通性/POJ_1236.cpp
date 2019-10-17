/*
    强连通缩点建图，找入度为0出度为0的点
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
int dfn[maxn], low[maxn], scc[maxn], head[maxn], scc_num, cnt, tot, ind[maxn], outd[maxn];
stack<int> st;
struct node
{
    int to, nxt;
} edg[maxn << 1];
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
        scc_num++;
        while (!st.empty())
        {
            int temp = st.top();
            st.pop();
            scc[temp] = scc_num;
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
    n = read<int>();
    memset(head, -1, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; i++)
    {
        int x = read<int>();
        while (x)
        {
            add(i, x);
            x = read<int>();
        }
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int u = 1; u <= n; u++)
    {
        for (int j = head[u]; ~j; j = edg[j].nxt)
        {
            int v = edg[j].to;
            if (scc[u] != scc[v])
            {
                ++ind[scc[v]];
                ++outd[scc[u]];
            }
        }
    }
    int res1 = 0, res2 = 0;
    for (int i = 1; i <= scc_num; i++)
        if (!ind[i])
            ++res1;
    for (int i = 1; i <= scc_num; i++)
        if (!outd[i])
            ++res2;
    res2 = max(res1, res2);
    if (scc_num == 1)
        res2 = 0;
    writeln(res1);
    writeln(res2);
    return 0;
}