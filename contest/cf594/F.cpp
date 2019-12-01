/*
    强连通缩点建图
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
const int maxn = 1e6 + 10;
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
int head[maxn], dfn[maxn], low[maxn], scc[maxn], vis[maxn], tot, scc_num, cnt;
stack<int> st;
void add(int x, int y)
{
    edg[tot].nxt = head[x];
    edg[tot].to = y;
    head[x] = tot++;
}
void tarjan(int u)
{
    st.push(u);
    low[u] = dfn[u] = ++cnt;
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
    if (low[u] == dfn[u])
    {
        ++scc_num;
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
    int t = read<int>();
    while (t--)
    {
        n = read<int>(), m = read<int>();
        scc_num = 0, tot = 0;
        memset(head, -1, sizeof(int) * (n + 1));
        memset(scc, 0, sizeof(int) * (n + 1));
        memset(low, 0, sizeof(int) * (n + 1));
        memset(dfn, 0, sizeof(int) * (n + 1));
        memset(vis, 0, sizeof(int) * (n + 1));
        for (int i = 0; i < m; i++)
        {
            int x = read<int>(), y = read<int>();
            if (x == y)
                continue;
            add(x, y);
        }
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i);
        int pos = 0;
        for (int u = 1; u <= n; u++)
            for (int j = head[u]; ~j; j = edg[j].nxt)
            {
                int v = edg[j].to;
                if (scc[u] != scc[v])
                    vis[scc[u]] = 1;
            }
        for (int i = 1; i <= scc_num; i++)
            if (!vis[i])
            {
                pos = i;
                break;
            }
        if (!pos || scc_num == 1)
        {
            puts("No");
            continue;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (scc[i] == pos)
                ++cnt;
        puts("Yes");
        printf("%d %d\n", cnt, n - cnt);
        for (int i = 1; i <= n; i++)
            if (scc[i] == pos)
                printf("%d ", i);
        puts("");
        for (int i = 1; i <= n; i++)
            if (scc[i] != pos)
                printf("%d ", i);
        puts("");
    }
    return 0;
}