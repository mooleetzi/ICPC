/*
    luogu3810
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
struct Node
{
    int a, b, c, cnt, res;
} t1[maxn], t2[maxn];
int cmpa(Node x, Node y)
{
    if (x.a == y.a)
    {
        if (x.b == y.b)
            return x.c < y.c;
        return x.b < y.b;
    }
    return x.a < y.a;
}
int cmpb(Node x, Node y)
{
    if (x.b == y.b)
        return x.c < y.c;
    return x.b < y.b;
}
int tot, n, maxk;
int c[maxn << 1];
int ans[maxn];
inline int lowbit(int x) { return x & (-x); }
void add(int pos, int x)
{
    while (pos <= maxk)
    {
        c[pos] += x;
        pos += lowbit(pos);
    }
}
int sum(int pos)
{
    int res = 0;
    while (pos)
    {
        res += c[pos];
        pos -= lowbit(pos);
    }
    return res;
}
void cdq(int l, int r)
{
    if (l == r)
        return;
    int m = l + r >> 1;
    cdq(l, m), cdq(m + 1, r);
    sort(t2 + l, t2 + m + 1, cmpb), sort(t2 + m + 1, t2 + r + 1, cmpb);
    int i = m + 1, j = l;
    for (; i <= r; i++)
    {
        while (t2[j].b <= t2[i].b && j <= m)
            add(t2[j].c, t2[j].cnt), j++;
        t2[i].res += sum(t2[i].c);
    }
    for (i = l; i < j; i++)
        add(t2[i].c, -t2[i].cnt);
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &maxk);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d", &t1[i].a, &t1[i].b, &t1[i].c);
    sort(t1 + 1, t1 + 1 + n, cmpa);
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        ++tmp;
        if (t1[i].a != t1[i + 1].a || t1[i].b != t1[i + 1].b || t1[i].c != t1[i + 1].c)
            t2[++tot] = t1[i], t2[tot].cnt = tmp, tmp = 0;
    }
    cdq(1, tot);
    for (int i = 1; i <= tot; i++)
        ans[t2[i].res + t2[i].cnt - 1] += t2[i].cnt;
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
