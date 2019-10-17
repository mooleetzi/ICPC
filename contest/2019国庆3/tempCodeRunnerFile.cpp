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
#define lson rt << 1
#define rson rt << 1 | 1
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k, mod;
const int maxn = 1e4 + 10;
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
int dfn[maxn], head[maxn], siz[maxn], dep[maxn];
int fa[maxn], top[maxn], son[maxn], w[maxn], cnt, tot, root;
struct node
{
    int to, nxt;
} edg[maxn << 1];
struct nodeT
{
    int l, r, lazy;
    set<int> s;
} tr[maxn << 2];
inline void pushup(int rt)
{
    tr[rt].s.insert(tr[rt << 1].s.begin(), tr[rt << 1].s.end());
    tr[rt].s.insert(tr[rt << 1 | 1].s.begin(), tr[rt << 1 | 1].s.end());
}
void build(int rt, int l, int r)
{
    tr[rt].l = l;
    tr[rt].r = r;
    tr[rt].lazy = 0;
    if (l == r)
    {
        tr[rt].s.clear();
        tr[rt].s.emplace(w[l]);
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt); //一定要更新父节点
}
set<int> query(int rt, int L, int R)
{
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l >= L && r <= R)
        return tr[rt].s;
    int mid = l + r >> 1;
    set<int> tmp;
    if (L <= mid)
    {
        set<int> cur = query(lson, L, R);
        tmp.insert(cur.begin(), cur.end());
    }
    if (R > mid)
    {
        set<int> cur = query(rson, L, R);
        tmp.insert(cur.begin(), cur.end());
    }
    return tmp;
}
void add(int x, int y)
{
    edg[tot].nxt = head[x];
    edg[tot].to = y;
    head[x] = tot++;
}
void dfs1(int u, int p)
{
    fa[u] = p;
    dep[u] = dep[p] + 1;
    siz[u] = 1;
    int maxsz = -1;
    for (int i = head[u]; ~i; i = edg[i].nxt)
    {
        int v = edg[i].to;
        if (v == p)
            continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if (siz[v] > maxsz)
        {
            maxsz = siz[v];
            son[u] = v;
        }
    }
}
void dfs2(int u, int t)
{
    dfn[u] = ++cnt;
    top[u] = t;
    w[cnt] = u;
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (int i = head[u]; ~i; i = edg[i].nxt)
    {
        int v = edg[i].to;
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}
inline set<int> qchain(int x, int y)
{
    set<int> tmp;
    set<int> ret;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        tmp = query(1, dfn[top[x]], dfn[x]);
        ret.insert(tmp.begin(), tmp.end());
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    tmp = query(1, dfn[x], dfn[y]);
    ret.insert(tmp.begin(), tmp.end());
    return ret;
}
void print(const set<int> &x)
{
    for (auto r : x)
        cout << r << " ";
    cout << endl;
}
set<int> temp[100];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t = read<int>();
    for (int cas = 1; cas <= t; cas++)
    {
        printf("Case %d:\n", cas);
        n = read<int>();
        memset(head, -1, sizeof(int) * (n + 1));
        memset(dfn, 0, sizeof(int) * (n + 1));
        memset(son, 0, sizeof(int) * (n + 1));
        memset(siz, 0, sizeof(int) * (n + 1));
        memset(fa, 0, sizeof(int) * (n + 1));
        memset(top, 0, sizeof(int) * (n + 1));
        memset(dep, 0, sizeof(int) * (n + 1));
        memset(w, 0, sizeof(int) * (n + 1));
        tot = cnt = 0;
        for (int i = 1; i < n; i++)
        {
            int x = read<int>(), y = read<int>();
            add(x, y);
            add(y, x);
        }
        dfs1(1, 0);
        dfs2(1, -1);
        build(1, 1, n);
        m = read<int>();
        while (m--)
        {
            int k = read<int>();
            for (int j = 1; j <= k; j++)
            {
                int x = read<int>(), y = read<int>();
                temp[j].clear();
                temp[j] = qchain(x, y);
            }
            set<int> res = temp[1];
            set<int> tmp;
            for (int j = 2; j <= k; j++)
            {
                tmp.clear();
                set_intersection(temp[j].begin(), temp[j].end(), res.begin(), res.end(), inserter(tmp, tmp.begin()));
                res = tmp;
            }
            writeln(res.size());
        }
    }
    return 0;
}