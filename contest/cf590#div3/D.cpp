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
}
char s[maxn];
struct segTree
{
    char ch;
    void setCh(char p) { ch = p; }
    struct node
    {
        int l, r;
        int sum;
    } tr[maxn << 2];
    inline void pushup(int rt)
    {
        tr[rt].sum = tr[lson].sum + tr[rson].sum;
    }
    void build(int rt, int l, int r)
    {
        tr[rt].l = l;
        tr[rt].r = r;
        if (l == r)
        {
            tr[rt].sum = s[l] == ch;
            return;
        }
        int mid = l + r >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(rt); //一定要更新父节点
    }
    void update(int rt, int L, int x)
    {
        int l = tr[rt].l;
        int r = tr[rt].r;
        if (l == r)
        {
            tr[rt].sum += x;
            return;
        }
        int mid = l + r >> 1;
        if (mid >= L)
            update(lson, L, x);
        else
            update(rson, L, x);
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
            ans += query(lson, L, R);
        if (R > mid)
            ans += query(rson, L, R);
        return ans;
    }
} seg[27];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    cin >> s + 1;
    int len = strlen(s + 1);
    for (int i = 0; i < 26; i++)
    {
        seg[i].setCh('a' + i);
        seg[i].build(1, 1, len);
    }
    int t = read<int>();
    while (t--)
    {
        int op, l, r;
        cin >> op >> l;
        if (op == 1)
        {
            char r;
            cin >> r;
            seg[s[l] - 'a'].update(1, l, -1);
            seg[r - 'a'].update(1, l, 1);
            s[l] = r;
        }
        else
        {
            cin >> r;
            int res = 0;
            for (int i = 0; i < 26; i++)
            {
                int cur = seg[i].query(1, l, r);
                if (cur)
                    ++res;
            }
            cout << res << "\n";
        }
    }
    return 0;
}