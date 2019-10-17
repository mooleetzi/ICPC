//线段树区间更改
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#define ll long long
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;
const int maxn = 1e5 + 10;
int n, q, m;
struct node
{
    int l, r;
    ll sum, lazy;
} tr[maxn << 2];
inline void pushup(int rt)
{
    tr[rt].sum = tr[lson].sum + tr[rson].sum;
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
        read(tr[rt].sum);
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt); //一定要更新父节点
}
void update(int rt, int L, int R, ll v)
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
        update(lson, L, R, v);
    if (R > mid)
        update(rson, L, R, v);
    pushup(rt); //更新父区间
}
ll query(int rt, int L, int R)
{
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l >= L && r <= R)
        return tr[rt].sum;
    pushdown(rt); //和update同理
    int mid = l + r >> 1;
    ll ans = 0;
    if (L <= mid)
        ans += query(lson, L, R);
    if (R > mid)
        ans += query(rson, L, R);
    return ans;
}