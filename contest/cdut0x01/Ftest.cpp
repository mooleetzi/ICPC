#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
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
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
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
template <typename T>
void _write(const T &t)
{
    write(t);
}
template <typename T, typename... Args>
void _write(const T &t, Args... args)
{
    write(t), pblank;
    _write(args...);
}
template <typename T, typename... Args>
inline void write_line(const T &t, const Args &... data)
{
    _write(t, data...);
    puts("");
}
struct segTree
{
    int num[maxn];
    struct node
    {
        int l, r;
        ll lsum, rsum, sum;
    } tr[maxn << 2];
    inline void pushup(int rt)
    {
        int l = tr[rt].l, r = tr[rt].r;
        int mid = (l + r) >> 1;
        tr[rt].lsum = tr[lson].lsum;
        tr[rt].rsum = tr[rson].rsum;
        tr[rt].sum = max(tr[lson].sum, tr[rson].sum);
        if (num[mid] <=num[mid + 1])
        {
            if (tr[lson].lsum == mid - l + 1)
                tr[rt].lsum = tr[lson].lsum + tr[rson].lsum;
            if (tr[rson].rsum == r - mid)
                tr[rt].rsum = tr[lson].rsum + tr[rson].rsum;
            tr[rt].sum = max(tr[rt].sum, tr[lson].rsum+tr[rson].lsum);
        }
    }
    void build(int rt, int l, int r)
    {
        tr[rt].l = l;
        tr[rt].r = r;
        if (l == r)
        {
            tr[rt].lsum = tr[rt].rsum = tr[rt].sum = 1;
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(rt); 
    }
    ll query(int rt, int L, int R)
    {
        int l = tr[rt].l;
        int r = tr[rt].r;
        if (l >= L && r <= R)
            return tr[rt].sum;
        int mid = l + r >> 1;
        ll ans = 0;
        if (L <= mid)
            ans = max(ans,query(lson, L, R));
        if (R > mid)
            ans =max(ans,query(rson, L, R));
        if (num[mid] <=num[mid + 1])
            ans = max(ans, min(mid - L + 1LL, tr[lson].rsum) + min(1LL*R - mid,tr[rson].lsum));
        return ans;
    }
} seg[2];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 1; i <= n;i++)
        seg[0].num[i]=read<int>(),seg[1].num[i]=-seg[0].num[i];
    seg[0].build(1, 1, n);
    seg[1].build(1, 1, n);
    m = read<int>();
    while(m--){
        int l = read<int>(), r = read<int>();
        writeln(max(seg[0].query(1, l, r), seg[1].query(1, l, r)));
    }
    return 0;
}