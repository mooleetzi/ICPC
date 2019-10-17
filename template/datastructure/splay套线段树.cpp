#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
using namespace std;
const int maxn = 5e4 + 10;
const int inf = 2147483647;
int n;
struct node
{
    int fa, val, cnt, ch[2], sz;
    void clear(){
        fa = val = cnt = ch[1] = ch[0] = sz = 0;
    }
}t[maxn*25];
int s[maxn << 2], tot;
int a[maxn];
inline int read()
{
    register int x = 0, f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if (ch=='-')
            f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = (x << 3) + (x << 1) + ch - 48;
        ch = getchar();
    }
    return x * f;
}
inline void pushup(int x){
    t[x].sz = t[ls(x)].sz + t[x].cnt + t[rs(x)].sz;
}
inline void clear(int x){
    t[x].clear();
}
inline int ws(int x){
    return rs(t[x].fa) == x;
}
inline void connect(int s,int f,int w){
    if (f)
        t[f].ch[w] = s;
    if (s)
        t[s].fa = f;
}
inline void rot(int x){
    int w = ws(x);
    int f = t[x].fa;
    int wf = ws(f);
    int ff = t[f].fa;
    int tson = t[x].ch[w ^ 1];
    connect(tson, f, w);
    connect(x, ff, wf);
    connect(f, x, w ^ 1);
    pushup(f);
    pushup(x);
}
inline void splay(int i,int x){
    for (int fa; (fa = t[x].fa);rot(x)){
        if (t[fa].fa&&ws(fa)==ws(x))
            rot(fa);
    }
    s[i] = x;
}
inline void insert(int i,int x){
    if (!s[i]){
        t[++tot].val = x;
        t[tot].sz = t[tot].cnt = 1;
        s[i] = tot;
        return;
    }
    int now = s[i];
    while(t[now].val!=x){
        if (x>t[now].val){
            if (!rs(now)){
                t[++tot].val = x;
                connect(tot, now, 1);
            }
            now = rs(now);
        }
        else
        {
            if (!ls(now)){
                t[++tot].val = x;
                connect(tot, now, 0);
            }
            now = ls(now);
        }
    }
    ++t[now].cnt;
    splay(i, now);
}
inline int find(int i,int x){
    int now = s[i];
    while(t[now].val!=x)
        now = t[now].ch[x > t[now].val];
    return now;
}
inline void del(int i,int x){
    int now = find(i, x);
    splay(i, now);
    if (t[now].cnt>1){
        --t[now].cnt;
        return;
    }
    if (!ls(now)&&!rs(now)){
        // clear(s[i]);
        s[i] = 0;
    }
    else if (!ls(now)){
        s[i] = rs(now);
        t[s[i]].fa = 0;
    }
    else if (!rs(now)){
        s[i] = ls(now);
        t[s[i]].fa = 0;
    }
    else
    {
        int left = ls(now);
        while(rs(left))
            left = rs(left);
        splay(i,left);
        connect(rs(now), left, 1);
        clear(now);
        pushup(left);
    }
}
inline int rnk(int i,int x){
    int now = s[i];
    int ans = 0;
    while (1)
    {
        if (!now)
            break;
        if (x>=t[now].val){
            ans += t[ls(now)].sz;
            if (x == t[now].val)
            {
                splay(i, now);
                break;
            }
            ans += t[now].cnt;
            now = rs(now);
        }
        else
            now = ls(now);
    }
    return ans;
}
inline int kth(int i,int k){
    int now = s[i];
    while(1){
        int left = t[now].sz - t[rs(now)].sz;
        if (k>t[ls(now)].sz&&k<=left)
            break;
        if (k<left)
            now = ls(now);
        else
        {
            k -= left;
            now = rs(now);
        }
    }
    splay(i, now);
    return t[now].val;
}
int pre(int i,int x){
    int ans = -inf;
    int now = s[i];
    while (now)
    {
        if (t[now].val < x)
            ans = max(t[now].val, ans);
        now = t[now].ch[x > t[now].val]; //寻找pre时，小于等于都往左找
    }
    return ans;
}
int next(int i,int x)
{
    int ans = inf;
    int now = s[i];
    while (now)
    {
        if (x < t[now].val)
            ans = min(ans, t[now].val);
        now = t[now].ch[x >= t[now].val]; //寻找next时，即使相等也得往右子树找
    }
    return ans;
}
void build(int rt,int l,int r){
    for (int i = l; i <= r;i++)
        insert(rt, a[i]);
    if (l==r)
        return;
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void update(int rt,int l,int r,int pos,int val){
    del(rt, a[pos]);
    insert(rt, val);
    if (l==r){
        a[pos] = val;
        return;
    }
    int mid = l + r >> 1;
    if (pos>mid)
        update(rt << 1 | 1, mid + 1, r, pos, val);
    else
        update(rt << 1, l, mid, pos, val);
}
int query_rnk(int rt,int l,int r,int ql,int qr,int val){
    if (l>qr||r<ql)
        return 0;
    if (l >= ql&&r<=qr)
        return rnk(rt, val);
    int mid = l + r >> 1;
    return query_rnk(rt << 1, l, mid, ql, qr, val) + query_rnk(rt << 1 | 1, mid + 1, r, ql, qr, val);
}
int query_kth(int l,int r,int k){
    int h = 0, t = 1e8;
    while(h<t){
        int mid = h + t >> 1;
        int now = query_rnk(1, 1, n, l, r, mid);
        if (now<k)
            h = mid + 1;
        else
            t = mid;
    }
    return h - 1;
}
int query_pre(int rt,int l,int r,int ql,int qr,int val){
    if (l>qr||r<ql)
        return -inf;
    if (l>=ql&&r<=qr)
        return pre(rt, val);
    int mid = l + r >> 1;
    return max(query_pre(rt << 1, l, mid, ql, qr, val), query_pre(rt << 1 | 1, mid + 1, r, ql, qr, val));
}
int query_next(int rt,int l,int r,int ql,int qr,int val){
    if (l > qr || r < ql)
        return inf;
    if (l >= ql && r <= qr)
        return next(rt, val);
    int mid = l + r >> 1;
    return min(query_next(rt << 1, l, mid, ql, qr, val), query_next(rt << 1 | 1, mid + 1, r, ql, qr, val));
}
int main(int argc, char const *argv[])
{
    n = read();
    int m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    while (m--)
    {
        int op, l, r, x;
        op=read();
        if (op == 1)
        {
            l = read(), r = read(), x = read();
            printf("%d\n", query_rnk(1, 1, n, l, r, x) + 1);
        }
        if (op == 2)
        {
            l = read(), r = read(), x = read();
            printf("%d\n", query_kth(l, r, x));
        }
        if (op == 3)
        {
            l = read(), x = read();
            update(1, 1, n, l, x);
        }
        if (op == 4)
        {
            l = read(), r = read(), x = read();
            printf("%d\n", query_pre(1, 1, n, l, r, x));
        }
        if (op == 5)
        {
            l = read(), r = read(), x = read();
            printf("%d\n", query_next(1, 1, n, l, r, x));
        }
    }
    return 0;
}