/*
    树剖板题
    luogu_3384
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
int dfn[maxn], head[maxn], siz[maxn], dep[maxn];
int fa[maxn], top[maxn], a[maxn], son[maxn], w[maxn], cnt, tot, root;
struct node
{
    int to, nxt;
} edg[maxn << 1];
struct nodeT
{
    int l, r;
    int sum, lazy;
} tr[maxn << 2];
inline void pushup(int rt)
{
    tr[rt].sum = (tr[lson].sum + tr[rson].sum) % mod;
}
inline void pushdown(int rt)
{

    ll len = tr[rt].r - tr[rt].l + 1;
    if (tr[rt].lazy)
    {
        tr[lson].lazy += tr[rt].lazy; //注意此题是区间加，固懒标记也应该是累加而不是覆盖
        tr[rson].lazy += tr[rt].lazy;
        tr[lson].sum += (len - (len >> 1)) * tr[rt].lazy;
        tr[rson].sum += (len >> 1) * tr[rt].lazy;
        tr[lson].sum %= mod;
        tr[rson].sum %= mod;
        tr[rt].lazy = 0;
    }
}
void build(int rt, int l, int r)
{
    tr[rt].l = l;
    tr[rt].r = r;
    tr[rt].lazy = 0;
    if (l == r)
    {
        tr[rt].sum = w[l];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt); //一定要更新父节点
}
void modify(int rt, int L, int R, int v)
{
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l >= L && r <= R)
    {
        tr[rt].lazy += v;
        tr[rt].sum += 1LL * (r - l + 1) * v;
        return;
    }
    pushdown(rt); //当前区间没有在之前返回代表当前区间并非包含于待查询区间，在向左右区间查询时需要先将懒标记下放
    int mid = l + r >> 1;
    if (L <= mid)
        modify(lson, L, R, v);
    if (R > mid)
        modify(rson, L, R, v);
    pushup(rt); //更新父区间
}
int query(int rt, int L, int R)
{
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l >= L && r <= R)
        return tr[rt].sum % mod;
    pushdown(rt); //和update同理
    int mid = l + r >> 1;
    int ans = 0;
    if (L <= mid)
        ans += query(lson, L, R);
    if (R > mid)
        ans += query(rson, L, R);
    return ans % mod;
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
    w[cnt] = a[u];
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
inline void mson(int x, int z)
{ //给x的子树加上z
    modify(1, dfn[x], dfn[x] + siz[x] - 1, z);
}
inline int qson(int x)
{
    return query(1, dfn[x], dfn[x] + siz[x] - 1);
}
inline void mchain(int x, int y, int z)
{ //修改一条链
    z %= mod;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        modify(1, dfn[top[x]], dfn[x], z);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    modify(1, dfn[x], dfn[y], z);
}
inline int qchain(int x, int y)
{
    int ret = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        ret += query(1, dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    ret += query(1, dfn[x], dfn[y]);
    return ret % mod;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    n = read<int>(), m = read<int>(), root = read<int>();
    mod = read<int>();
    for (int i = 1; i <= n; i++)
        a[i] = read<int>();
    memset(head, -1, sizeof(int) * (n + 1));
    for (int i = 1; i < n; i++)
    {
        int x = read<int>(), y = read<int>();
        add(x, y);
        add(y, x);
    }
    dfs1(root, 0);
    dfs2(root, root);
    build(1, 1, n);
    while (m--)
    {
        int op = read<int>();
        if (op == 1)
        {
            int x = read<int>(), y = read<int>(), z = read<int>();
            mchain(x, y, z);
        }
        else if (op == 2)
        {
            int x = read<int>(), y = read<int>();
            writeln(qchain(x, y));
        }
        else if (op == 3)
        {
            int x = read<int>(), z = read<int>();
            mson(x, z);
        }
        else if (op == 4)
        {
            int x = read<int>();
            writeln(qson(x));
        }
    }
    return 0;
}