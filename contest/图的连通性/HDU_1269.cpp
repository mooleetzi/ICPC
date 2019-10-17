/*
    tarjan模板题，求强连通分量个数
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
int head[maxn], dfn[maxn], low[maxn], scc[maxn], tot, scc_num, cnt;
stack<int> st;
void add(int x, int y)
{
    edg[tot].to = y;
    edg[tot].nxt = head[x];
    head[x] = tot++;
}
void init()
{
    tot = scc_num = cnt = 0;
    memset(head, -1, sizeof(int) * (n + 1));
    memset(dfn, 0, sizeof(int) * (n + 1));
    memset(low, 0, sizeof(int) * (n + 1));
    memset(scc, 0, sizeof(int) * (n + 1));
    while (!st.empty())
        st.pop();
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
        while (1)
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
#endif
    while (~scanf("%d%d", &n, &m) && (n + m))
    {
        init();
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y);
        }
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i);
        if (scc_num == 1)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}