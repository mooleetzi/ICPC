#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define inf 2147483647
#define eps 1e-9
#define lb(x) (x & -x)
using namespace std;
typedef long long ll;
typedef double db;
struct task
{
    int op, id, x, y, v;
    task() {}
    task(int _op, int _id, int _x, int _y, int _v)
    {
        op = _op, id = _id, x = _x, y = _y, v = _v;
    }
} t[500001], t1[500001], t2[500001];
int n, m, mi = inf, mx = -inf, x, y, k, totq = 0, cnt = 0, num[500001], ans[500001], tr[500001];
char op[5];
void add(int x, int v)
{
    for (; x <= n; x += lb(x))
    {
        tr[x] += v;
    }
}
int query(int x)
{
    int ret = 0;
    for (; x; x -= lb(x))
    {
        ret += tr[x];
    }
    return ret;
}
void solve(int ql, int qr, int l, int r)
{
    if (ql > qr || l > r)
        return;
    if (ql == qr)
    {
        for (int i = l; i <= r; i++)
        {
            if (t[i].op)
                ans[t[i].id] = ql;
        }
        return;
    }
    int mid = (ql + qr) / 2, cnt1 = 0, cnt2 = 0;
    for (int i = l; i <= r; i++)
    {
        if (t[i].op)
        {
            int nw = query(t[i].y) - query(t[i].x - 1);
            if (nw >= t[i].v)
                t1[++cnt1] = t[i];
            else
            {
                t[i].v -= nw;
                t2[++cnt2] = t[i];
            }
        }
        else
        {
            if (t[i].v <= mid)
            {
                t1[++cnt1] = t[i];
                add(t[i].id, t[i].x);
            }
            else
                t2[++cnt2] = t[i];
        }
    }
    for (int i = 1; i <= cnt1; i++)
    {
        if (!t1[i].op)
        {
            add(t1[i].id, -t1[i].x);
        }
    }
    for (int i = 1; i <= cnt1; i++)
        t[i + l - 1] = t1[i];
    for (int i = 1; i <= cnt2; i++)
        t[i + l + cnt1 - 1] = t2[i];
    solve(ql, mid, l, l + cnt1 - 1);
    solve(mid + 1, qr, l + cnt1, r);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        mi = min(mi, x);
        mx = max(mx, x);
        num[i] = x;
        t[++cnt] = task(0, i, 1, 0, x);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", op);
        if (op[0] == 'Q')
        {
            scanf("%d%d%d", &x, &y, &k);
            t[++cnt] = task(1, ++totq, x, y, k);
        }
        else
        {
            scanf("%d%d", &x, &y);
            mi = min(mi, y);
            mx = max(mx, y);
            t[++cnt] = task(0, x, -1, 0, num[x]);
            t[++cnt] = task(0, x, 1, 0, y);
            num[x] = y;
        }
    }
    solve(mi, mx, 1, cnt);
    for (int i = 1; i <= totq; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}