/*
    最小点覆盖+找出最小点覆盖的点集
 */
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 1e3 + 10;
template <class T>
inline T read(T &ret)
{
    int f = 1;
    ret = 0;
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
int llink[maxn], rlink[maxn], visl[maxn], visr[maxn];
vector<int> g[maxn];
inline void init()
{
    memset(llink, -1, sizeof(int) * (m + 2));
    memset(rlink, -1, sizeof(int) * (n + 2));
    for (int i = 1; i <= n; i++)
        g[i].clear();
}
inline void add(int x, int y)
{
    g[x].emplace_back(y);
}
int find(int u)
{
    visl[u] = 1;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = g[u][i];
        if (!visr[v])
        {
            visr[v] = 1;
            if (llink[v] == -1 || find(llink[v]))
            {
                llink[v] = u;
                rlink[u] = v;
                return 1;
            }
        }
    }
    return 0;
}
int maxMacth()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(visr, 0, sizeof(int) * (m + 1));
        res += find(i);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (cin >> n >> m >> k && (m + n + k))
    {
        init();
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            add(x, y);
        }
        int ans = maxMacth();
        memset(visl, 0, sizeof visl);
        memset(visr, 0, sizeof visr);
        for (int i = 1; i <= n; i++) //再次匹配，找到哪些点需要匹配
            if (rlink[i] == -1)
                find(i);
        cout << ans << " ";
        for (int i = 1; i <= n; i++)
            if (!visl[i])
                cout << "r" << i << " ";
        for (int i = 1; i <= m; i++)
            if (visr[i])
                cout << "c" << i << ' ';
        cout << "\n";
    }
    return 0;
}
