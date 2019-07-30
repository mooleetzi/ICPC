//单点查询，区间更新
#include <iostream>
using namespace std;
const int maxn = 5e5 + 50;
using ll = long long;
ll c[maxn];
int n, m;
inline int lowbit(int x)
{
    return x & (-x);
}
void add(int x, int y)
{
    while (x <= n)
    {
        c[x] += y;
        x += lowbit(x);
    }
}
void add(int l, int r, int x)
{
    add(l, x);
    add(r + 1, -x);
}
ll query(int x)
{
    ll ans = 0;
    while (x)
    {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
ll a[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }
    for (int i = 0; i < m; i++)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            add(x, y, k);
        }
        else
        {
            cin >> x;
            cout << query(x) << "\n";
        }
    }
    return 0;
}
