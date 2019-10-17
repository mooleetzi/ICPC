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
int n, m, k, q;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
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
char s[maxn];
struct node
{
    int l, r, a[6][6];
    node() {}
    void init(int x)
    {
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                if (i == j)
                    a[i][j] = 0;
                else
                    a[i][j] = inf;
        if (x == -1)
            for (int i = 0; i < 5; i++)
                a[i][i] = inf;
        if (x == 2)
            a[0][0] = 1, a[0][1] = 0;
        if (x == 0)
            a[1][1] = 1, a[1][2] = 0;
        if (x == 1)
            a[2][2] = 1, a[2][3] = 0;
        if (x == 9)
            a[3][3] = 1, a[3][4] = 0;
        if (x == 8)
            a[3][3] = a[4][4] = 1;
    }
} tr[maxn << 2];
inline node add(const node &a, const node &b)
{
    node ret;
    ret.init(-1);
    ret.l = a.l;
    ret.r = b.r;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            for (int k = 0; k < 5; ++k)
                ret.a[i][j] = min(ret.a[i][j], a.a[i][k] + b.a[k][j]);
    return ret;
}
inline void push_up(int rt)
{
    tr[rt] = add(tr[rt << 1], tr[rt << 1 | 1]);
}
inline void build(int rt, int l, int r)
{
    tr[rt].l = l, tr[rt].r = r;
    if (l == r)
    {
        tr[rt].init(s[l] - '0');
        return;
    }
    int mid = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}
inline node query(int rt, int L, int R)
{
    int l = tr[rt].l, r = tr[rt].r;
    if (l >= L && r <= R)
        return tr[rt];
    int mid = l + r >> 1;
    if (R <= mid)
        return query(rt << 1, L, R);
    if (L > mid)
        return query(rt << 1 | 1, L, R);
    return add(query(rt << 1, L, mid), query(rt << 1 | 1, mid + 1, R));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%d%d%s", &n, &q, s + 1);
    reverse(s + 1, s + 1 + n);
    build(1, 1, n);
    while (q--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        node tmp = query(1, n - r + 1, n - l + 1);
        int res = -1;
        if (tmp.a[0][4] != inf)
            res = tmp.a[0][4];
        printf("%d\n", res);
    }
    return 0;
}
