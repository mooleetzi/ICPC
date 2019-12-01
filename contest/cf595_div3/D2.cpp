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
#define pblank putchar(' ')
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 2e5 + 10;
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
    int l, r, idx;
    node() {}
    node(int ll, int rr, int i) : l(ll), r(rr), idx(i) {}
    bool operator<(const node &t) const
    {
        if (r == t.r)
            return l < t.l;
        return r < t.r;
    }
};
vector<node> vec;
struct Node
{
    int l, r;
    ll sum, lazy;
} tr[maxn << 2];
inline void pushup(int rt)
{
    tr[rt].sum = max(tr[lson].sum, tr[rson].sum);
}
inline void pushdown(int rt)
{

    if (tr[rt].lazy)
    {
        tr[lson].lazy += tr[rt].lazy; //注意此题是区间加，固懒标记也应该是累加而不是覆盖
        tr[rson].lazy += tr[rt].lazy;
        tr[lson].sum += tr[rt].lazy;
        tr[rson].sum += tr[rt].lazy;
        tr[rt].lazy = 0;
    }
}
void build(int rt, int l, int r)
{
    tr[rt].l = l;
    tr[rt].r = r;
    tr[rt].lazy = tr[rt].sum = 0;
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void update(int rt, int L, int R, ll v)
{
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l >= L && r <= R)
    {
        tr[rt].lazy += v;
        tr[rt].sum += v;
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
        ans = max(ans, query(lson, L, R));
    if (R > mid)
        ans = max(ans, query(rson, L, R));
    return ans;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), k = read<int>();
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        int x = read<int>(), y = read<int>();
        vec.emplace_back(x, y, i + 1);
        maxx = max(maxx, y);
    }
    sort(vec.begin(), vec.end());
    build(1, 1, maxx);
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        int cur = query(1, vec[i].l, vec[i].r);
        if (cur < k)
            update(1, vec[i].l, vec[i].r, 1);
        else
            res.emplace_back(vec[i].idx);
    }
    sort(res.begin(), res.end());
    writeln(res.size());
    for (int x : res)
        write(x), pblank;
    return 0;
}