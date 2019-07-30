//单点更新，区间查询
#include <iostream>
using namespace std;
const int maxn = 500000 + 50;
using ll = long long;
ll c[maxn];
int n, m;
inline int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int y)
{
    while (x <= n)
    {
        c[x] += y;
        x += lowbit(x);
    }
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
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(i, x);
    }
    for (int i = 0; i < m; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
            update(x, y);
        else
            cout << query(y) - query(x - 1) << "\n";
    }
    return 0;
}
