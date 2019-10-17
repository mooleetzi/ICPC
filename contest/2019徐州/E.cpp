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
const int maxn = 5e5 + 10;
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
int a[maxn];
struct node
{
    int l, r, maxx, rmax;
} tr[maxn << 2];
int idx[maxn << 2];
void push_up(int rt)
{
    tr[rt].maxx = max(tr[rt << 1].maxx, tr[rt << 1 | 1].maxx);
}
void build(int rt, int l, int r)
{
    tr[rt].l = l;
    tr[rt].r = r;
    if (l == r)
    {
        tr[rt].maxx = a[l];
        idx[l] = rt;
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}
int query(int rt, int id, int val)
{
    int l = tr[rt].l;
    int r = tr[rt].r;
    if (l == r)
    {
        return l - id - 1;
    }
    if (tr[rt << 1 | 1].maxx >= val)
        return query(rt << 1 | 1, id, val);
    else if (tr[rt << 1].maxx >= val)
        return query(rt << 1, id, val);
    return -1;
}
int rmax[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), m = read<int>();
    for (int i = 1; i <= n; i++)
        a[i] = read<int>();
    rmax[n] = 0;
    for (int i = n; i >= 1; i--)
        rmax[i] = max(a[i + 1], rmax[i + 1]);
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        if (rmax[i] < a[i] + m)
        {
            write(-1);
            if (i == n)
                puts("");
            else
                putchar(' ');
            continue;
        }
        write(query(1, i, a[i] + m));
        if (i == n)
        {
            puts("");
        }
        else
            putchar(' ');
    }
    return 0;
}