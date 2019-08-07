//典型的线段树区间更改板子
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
int main(int argc, char const *argv[])
{
    read(n);
    read(m);
    build(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        char ch = getchar();
        if (ch == 'Q')
        {
            int l, r;
            read(l);
            read(r);
            write(query(1, l, r));
            putchar('\n');
        }
        else
        {
            int l, r;
            ll c;
            read(l), read(r), read(c);
            update(1, l, r, c);
        }
    }
    return 0;
}
