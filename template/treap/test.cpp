#include <bits/stdc++.h>
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
using namespace std;
const int maxn = 5e4 + 100;
const int inf = 2147483647;
int root;
struct node
{
    int ch[2], val, cnt, sz, fa;
    void clear()
    {
        ch[0] = ch[1] = val = cnt = sz = fa = 0;
    }
} t[maxn * 25];
int tot, n;
int a[maxn];
int seg[maxn << 2];
inline int read()
{
    register int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 48;
        ch = getchar();
    }
    return x * f;
}
inline void clear(int x)
{
    t[x].clear();
}
inline void pushup(int x)
{
    t[x].sz = t[rs(x)].sz + t[rs(x)].sz + t[x].cnt;
}
inline int ws(int x)
{
    return rs(t[x].fa) == x;
}
inline void connect(int s, int f, int w)
{
    if (f)
        t[f].ch[w] = s;
    if (s)
        t[s].fa = f;
}
inline void rot(int x)
{
    int f = t[x].fa;
    int ff = t[f].fa;
    int w = ws(x);
    int wf = ws(f);
    int tson = t[x].ch[w ^ 1];
    connect(tson, f, w);
    connect(x, ff, wf);
    connect(f, x, w ^ 1);
    pushup(f);
    pushup(x);
}
inline void splay(int &rt, int x)
{
    for (int fa; (fa = t[x].fa); rot(x))
        if (t[fa].fa && ws(fa) == ws(x))
            rot(fa);
    rt = x;
}
void insert(int &rt, int x)
{
    if (!rt)
    {
        int now = ++tot;
        t[now].cnt = t[now].sz = 1;
        t[now].val = x;
        rt = now;
        return;
    }
    int now = rt;
    while (t[now].val != x)
    {
        if (x > t[now].val)
        {
            if (!rs(now))
            {
                int z = ++tot;
                t[z].val = x;
                connect(z, now, 1);
            }
            now = rs(now);
        }
        else
        {
            if (!ls(now))
            {
                int z = ++tot;
                t[z].val = x;
                connect(z, now, 0);
            }
            now = ls(now);
        }
    }
    ++t[now].cnt;
    splay(rt, now);
}
int find(int rt, int x)
{
    int now = rt;
    while (t[now].val != x)
        now = t[now].ch[x > t[now].val];
    return now;
}
void del(int &rt, int x)
{
    int now = find(rt, x);
    splay(rt, now);
    if (!now)
        return;
    if (t[now].cnt > 1)
    {
        t[now].cnt--;
        pushup(now);
        return;
    }
    if (!rs(now) && !ls(now))
    {
        clear(now);
        rt = 0;
        return;
    }
    else if (!ls(now))
    {
        rt = rs(now);
        t[rt].fa = 0;
        pushup(rt);
        clear(now);
    }
    else if (!rs(now))
    {
        rt = ls(now);
        t[rt].fa = 0;
        pushup(rt);
        clear(now);
    }
    else
    {
        int left = ls(now);
        while (rs(left))
            left = rs(left);
        splay(rt, left);
        connect(rs(now), left, 1);
        clear(now);
        pushup(rt);
    }
}
int rnk(int &rt, int x)
{
    int now = rt;
    int ans = 0;
    while (1)
    {
        if (!now)
            break;
        if (x >= t[now].val)
        {
            ans += t[ls(now)].sz;
            if (x > t[now].val)
            {
                ans += t[now].cnt;
                now = rs(now);
            }
            else
            {
                splay(rt, now);
                break;
            }
        }
        else
        {
            now = ls(now);
        }
    }
    return ans;
}
int kth(int &rt, int k)
{
    int now = rt;
    while (1)
    {
        int left = t[now].sz - t[rs(now)].sz;
        if (k > t[ls(now)].sz && k <= left)
            break;
        if (k < left)
            now = ls(now);
        else
        {
            k -= left;
            now = rs(now);
        }
    }
    splay(rt, now);
    return t[now].val;
}
int pre(int rt, int x)
{
    int now = rt;
    int ans = -inf;
    while (now)
    {
        if (x > t[now].val)
        {
            ans = max(ans, t[now].val);
            now = rs(now);
        }
        else
            now = ls(now);
    }
    return ans;
}
int next(int rt, int x)
{
    int now = rt;
    int ans = inf;
    while (now)
    {
        if (x < t[now].val)
        {
            ans = min(ans, t[now].val);
            now = ls(now);
        }
        else
            now = rs(now);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    int op, x;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> op >> x;
        if (op == 1)
            insert(root,x);
        else if (op == 2)
            del(root,x);
        else if (op == 3)
            cout << rnk(root,x) << "\n";
        else if (op == 4)
            cout << kth(root,x) << "\n";
        else if (op == 5)
            cout << pre(root,x) << "\n";
        else if (op == 6)
            cout << next(root,x) << "\n";
    }
    return 0;
}