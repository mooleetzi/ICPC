/*
    带修区间kth rnk nxt pre
    无旋treap套线段树
*/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ls(x) tr[x].ch[0]
#define rs(x) tr[x].ch[1]
using namespace std;
const int inf = 2147483647;
const int maxn = 5e4 + 100;
int tot;
int n, m;
struct tnode
{
    int key, sz, val, ch[2];
} tr[maxn * 25]; //平衡树节点为2log(n)*n
int seg[maxn << 2];
int a[maxn];
inline void pushup(int rt)
{
    tr[rt].sz = tr[ls(rt)].sz + tr[rs(rt)].sz + 1;
}
inline void split(int rt, int &x, int &y, int val)
{
    if (!rt)
    {
        x = y = 0;
        return;
    }
    if (tr[rt].val <= val)
    {
        x = rt;
        split(rs(rt), rs(x), y, val);
    }
    else
    {
        y = rt;
        split(ls(rt), x, ls(y), val);
    }
    pushup(rt);
}
inline void merge(int &rt, int x, int y)
{
    if (!x || !y)
    {
        rt = x + y;
        return;
    }
    if (tr[x].key < tr[y].key)
    {
        rt = x;
        merge(rs(rt), rs(x), y);
    }
    else
    {
        rt = y;
        merge(ls(rt), x, ls(y));
    }
    pushup(rt);
}
int kth(int rt, int k)
{
    while (tr[ls(rt)].sz + 1 != k)
    {
        if (tr[ls(rt)].sz < k)
        {
            k -= tr[ls(rt)].sz + 1;
            rt = rs(rt);
        }
        else
        {
            rt = ls(rt);
        }
    }
    return tr[rt].val;
}
int rnk(int &rt, int val)
{
    int x, y, ans;
    x = y = 0;
    split(rt, x, y, val - 1);
    ans = tr[x].sz;
    merge(rt, x, y);
    return ans;
}
void insert(int &rt, int val)
{
    int x, y, z;
    z = ++tot;
    x = y = 0;
    tr[z].val = val;
    tr[z].key = rand();
    tr[z].sz = 1;
    split(rt, x, y, val - 1);
    merge(x, x, z);
    merge(rt, x, y);
}
void erase(int &rt, int val)
{
    int x, y, z;
    x = y = z = 0;
    split(rt, x, y, val);
    split(x, x, z, val - 1);
    merge(z, ls(z), rs(z));
    merge(x, x, z);
    merge(rt, x, y);
}
int pre(int &rt, int val)
{
    int x = 0, y = 0;
    int ans = -inf;
    split(rt, x, y, val - 1);
    if (tr[x].sz)
        ans = kth(x, tr[x].sz);
    merge(rt, x, y);
    return ans;
}
int next(int &rt, int val)
{
    int x = 0, y = 0;
    int ans = inf;
    split(rt, x, y, val);
    if (tr[y].sz)
        ans = kth(y, 1);
    merge(rt, x, y);
    return ans;
}
void build(int rt, int l, int r)
{
    for (int i = l; i <= r; i++)
        insert(seg[rt], a[i]);
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
int query_rnk(int rt, int l, int r, int ql, int qr, int val)
{
    if (l > qr || r < ql)
        return 0;
    if (l >= ql && r <= qr)
        return rnk(seg[rt], val);
    int mid = l + r >> 1;
    return query_rnk(rt << 1, l, mid, ql, qr, val) + query_rnk(rt << 1 | 1, mid + 1, r, ql, qr, val);
}
int query_kth(int ql, int qr, int k)
{
    int h = 0, t = 1e8 + 1;
    while (h < t)
    {
        int mid = h + t >> 1;
        int now = query_rnk(1, 1, n, ql, qr, mid);
        if (now < k)
            h = mid + 1;
        else
            t = mid;
    }
    return h - 1;
}
void update(int rt, int l, int r, int pos, int val)
{
    erase(seg[rt], a[pos]);
    insert(seg[rt], val);
    if (l == r)
    {
        a[pos] = val;
        return;
    }
    int mid = l + r >> 1;
    if (pos > mid)
        update(rt << 1 | 1, mid + 1, r, pos, val);
    else
        update(rt << 1, l, mid, pos, val);
}
int query_pre(int rt, int l, int r, int ql, int qr, int val)
{
    int ans = -inf;
    if (r < ql || l > qr)
        return ans;
    int mid = l + r >> 1;
    if (l >= ql && r <= qr)
        return pre(seg[rt], val);
    return max(query_pre(rt << 1, l, mid, ql, qr, val), query_pre(rt << 1 | 1, mid + 1, r, ql, qr, val));
}
int query_next(int rt, int l, int r, int ql, int qr, int val)
{
    int ans = inf;
    if (r < ql || l > qr)
        return ans;
    int mid = l + r >> 1;
    if (l >= ql && r <= qr)
        return next(seg[rt], val);
    return min(query_next(rt << 1, l, mid, ql, qr, val), query_next(rt << 1 | 1, mid + 1, r, ql, qr, val));
}
int main(int argc, char const *argv[])
{
    srand(time(0));
    read(n), read(m);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    build(1, 1, n);
    while (m--)
    {
        int op, l, r, x;
        read(op);
        if (op == 1)
        {
            read(l), read(r), read(x);
            printf("%d\n", query_rnk(1, 1, n, l, r, x) + 1);
        }
        if (op == 2)
        {
            read(l), read(r), read(x);
            printf("%d\n", query_kth(l, r, x));
        }
        if (op == 3)
        {
            read(l), read(x);
            update(1, 1, n, l, x);
        }
        if (op == 4)
        {
            read(l), read(r), read(x);
            printf("%d\n", query_pre(1, 1, n, l, r, x));
        }
        if (op == 5)
        {
            read(l), read(r), read(x);
            printf("%d\n", query_next(1, 1, n, l, r, x));
        }
    }
    return 0;
}
