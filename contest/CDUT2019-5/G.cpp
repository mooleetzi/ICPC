//线段树区间更新,
//tr数组维护区间最小值，剪支判断：当前值大于v，则跳过，小于则更新
//没有用懒标记，暴力更新区间
//每次需要清空保存本次可能用到的tr区间，至少sizeof(type)*(n<<2)
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;
const int mod = 1 << 30;
const int maxn = 1e5 + 10;
unsigned x, y, z;
int n, m;
ll tr[maxn << 2];
void pushup(int rt)
{
    tr[rt] = min(tr[rt << 1], tr[rt << 1 | 1]);
}
void update(int rt, int l, int r, int L, int R, ll v)
{
    if (tr[rt] >= v)
        return;
    if (l == r)
    {
        tr[rt] = v;
        return;
    }
    int mid = l + r >> 1;
    if (L <= mid)
        update(rt << 1, l, mid, L, R, v);
    if (R > mid)
        update(rt << 1 | 1, mid + 1, r, L, R, v);
    pushup(rt);
}
ll query(int rt, int l, int r, int L, int R)
{
    if (l >= L && r <= R)
        return tr[rt];
    int mid = l + r >> 1;
    if (L <= mid)
        return query(rt << 1, l, mid, L, R);
    if (R > mid)
        return query(rt << 1 | 1, mid + 1, r, L, R);
}
inline unsigned f()
{
    x = x ^ (x << 11);
    x = x ^ (x >> 4);
    x = x ^ (x << 5);
    x = x ^ (x >> 14);
    unsigned w = x ^ (y ^ z);
    x = y;
    y = z;
    z = w;
    return z;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> x >> y >> z;
        memset(tr, 0, 8 * (n << 2)); //清空线段树
        for (int i = 0; i < m; i++)
        {
            unsigned f0 = f(), f1 = f(), f2 = f();
            int l = min(f0 % n + 1, f1 % n + 1);
            int r = max(f0 % n + 1, f1 % n + 1);
            int v = f2 % mod;
            update(1, 1, n, l, r, v);
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll val = query(1, 1, n, i, i);
            val *= (ll)i;
            ans ^= val;
        }
        cout << ans << "\n";
    }
    return 0;
}
