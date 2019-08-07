/* 
看到很多解法，但这篇线段树解法让我感觉是最巧妙的
数据说明：
    线段树维护区间最大值以及区间从左往右上升长度
一下思路来自大神博客，仅作复述
对于查询一个节点t,v 即查询t表示区间以v作为起点的答案
若t->maxx<v直接返回0，总的区间最大值小于v，这个区间不可能贡献答案
否则若t->lson->maxx>v 此时只需关注左区间，因为右区间此时的贡献值和v不相关
否则对右区间递归查询
*/
#include <bits/stdc++.h>
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 1e5 + 10;
const int mod = 998244353;
int pre[maxn];
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
int a[maxn];
struct node
{
    int l, r, cnt, maxx;
} tr[maxn << 2];
int query(int rt, int v)
{
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l == r)
        return tr[rt].maxx > v;
    if (tr[rt].maxx < v)
        return 0;
    int mid = l + r >> 1;
    if (tr[lson].maxx > v) //疑惑，为什么写出tr[rson].cnt+query(lson,v)答案不对
                           //啊左右区间和大区间并不相等，大区间=左区间+右区间贡献
        return tr[rt].cnt - tr[lson].cnt + query(lson, v);
    else
        return query(rson, v);
}
void pushup(int rt)
{
    tr[rt].maxx = max(tr[lson].maxx, tr[rson].maxx);
    tr[rt].cnt = tr[lson].cnt + query(rson, tr[lson].maxx);
}
void build(int rt, int l, int r)
{
    tr[rt].l = l;
    tr[rt].r = r;
    if (l == r)
    {
        tr[rt].cnt = 1;
        tr[rt].maxx = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void update(int rt, int L, int v)
{
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l == r && l == L)
    {
        tr[rt].maxx = v;
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid)
        update(lson, L, v);
    else
        update(rson, L, v);
    pushup(rt);
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        while (m--)
        {
            int p, q;
            cin >> p >> q;
            update(1, p, q);
            cout << tr[1].cnt << "\n";
            update(1, p, a[p]);
        }
    }
    return 0;
}
