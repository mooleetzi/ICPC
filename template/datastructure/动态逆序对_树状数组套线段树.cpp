/*
    用树状数组访问位置
    用线段树访问权值
    每个点的贡献就是与其权值和位置大小关系不等的点的个数
*/
#include <cstdio>
#define ll long long
#define low(x) (x & (-x))
const int N = 1e5 + 10, M = 3e7 + 10;
int n, m, tot;
ll ans;
int a[N], pos[N], quea[N], queb[N];
int rt[N], t[M], ls[M], rs[M];
void change(int &p, int l, int r, int x, int y)
{
    if (!p)
        p = ++tot;
    t[p] += y;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (x <= mid)
        change(ls[p], l, mid, x, y);
    else
        change(rs[p], mid + 1, r, x, y);
}
int query(int l, int r, int x, int mode)
{
    int cnta = 0, cntb = 0, sum = 0, mid;
    for (int i = l - 1; i; i -= low(i))
        quea[++cnta] = rt[i];
    for (int i = r; i; i -= low(i))
        queb[++cntb] = rt[i];
    l = 1, r = n;
    while (l != r)
    {
        mid = (l + r) >> 1;
        if (x > mid)
        {
            if (mode)
            {
                for (int i = 1; i <= cnta; ++i)
                    sum -= t[ls[quea[i]]];
                for (int i = 1; i <= cntb; ++i)
                    sum += t[ls[queb[i]]];
            }
            for (int i = 1; i <= cnta; ++i)
                quea[i] = rs[quea[i]];
            for (int i = 1; i <= cntb; ++i)
                queb[i] = rs[queb[i]];
            l = mid + 1;
        }
        else
        {
            if (!mode)
            {
                for (int i = 1; i <= cnta; ++i)
                    sum -= t[rs[quea[i]]];
                for (int i = 1; i <= cntb; ++i)
                    sum += t[rs[queb[i]]];
            }
            for (int i = 1; i <= cnta; ++i)
                quea[i] = ls[quea[i]];
            for (int i = 1; i <= cntb; ++i)
                queb[i] = ls[queb[i]];
            r = mid;
        }
    }
    return sum;
}
int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
        pos[a[i]] = i;
        ans += query(1, i - 1, a[i], 0);
        for (int j = i; j <= n; j += low(j))
            change(rt[j], 1, n, a[i], 1);
    }
    printf("%lld\n", ans);
    for (int i = 1, x; i < m; ++i)
    {
        x = read();
        ans -= query(1, pos[x] - 1, x, 0);
        ans -= query(pos[x] + 1, n, x, 1);
        printf("%lld\n", ans);
        for (int j = pos[x]; j <= n; j += low(j))
            change(rt[j], 1, n, x, -1);
    }
    return 0;
}