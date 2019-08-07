//线段树区间更新
//对于单点，线段树维护下更新并将lazy赋值为0
//对于区间，加上lazy标记
#include <algorithm>
#include <cstring>
#include <iostream>
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;
using ll = long long;
const int mod = 1 << 30;
const int maxn = 2e5 + 10;
int n, m;
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
    int lazy, val, l, r;
} tr[maxn << 2];
int a[maxn];
void pushdown(int rt)
{
    if (tr[rt].lazy)
    {
        tr[lson].val = max(tr[lson].val, tr[rt].lazy);
        tr[rson].val = max(tr[rson].val, tr[rt].lazy);
        tr[lson].lazy = max(tr[rt].lazy, tr[lson].lazy);
        tr[rson].lazy = max(tr[rt].lazy, tr[rson].lazy);
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
        read(tr[rt].val);
        a[l] = tr[rt].val;
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void update(int rt, int L, int v)
{
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l == r)
    {
        tr[rt].val = v;
        tr[rt].lazy = 0; //此题单点更新优先级大于懒标记
        return;
    }
    int mid = l + r >> 1;
    pushdown(rt); //没有返回代表不是完全包含于待查询区间，需要先下放懒标记再向左右区间查询
    if (L <= mid)
        update(rt << 1, L, v);
    else
        update(rt << 1 | 1, L, v);
}
void query(int rt, int L, int R)
{
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l == r)
    {
        a[l] = max(tr[rt].val, tr[rt].lazy);
        return;
    }
    pushdown(rt); //同update
    int mid = l + r >> 1;
    if (L <= mid)
        query(rt << 1, L, R);
    if (R > mid)
        query(rt << 1 | 1, L, R);
}
int main(int argc, char const *argv[])
{
    read(n);
    build(1, 1, n);
    read(m);
    for (int i = 0; i < m; i++)
    {
        int op, x, y;
        read(op);
        if (op == 1)
        {
            read(x);
            read(y);
            update(1, x, y);
        }
        else
        {
            read(x);
            tr[1].lazy = max(tr[1].lazy, x);
        }
    }
    query(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        write(a[i]);
        putchar(' ');
    }
    return 0;
}
