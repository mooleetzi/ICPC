//dijkstra最短路径，居然没想到简直憨憨
//在加入堆时，同时记录一下到目前点最短路径的边由哪个海盗占领
//松弛操作时通过判断当前边和之前记录的海盗是否为同一个
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
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
vector<pa> g[maxn];
int vis[maxn];
int dis[maxn];
struct node
{
    int to, dis, fa;
    node(int a, int b, int c) : to(a), dis(b), fa(c) {}
    node() {}
    bool operator<(const node &x) const
    {
        return dis > x.dis;
    }
};
void dijk()
{
    memset(dis, 0x3f, sizeof(int) * (n + 1));
    memset(vis, 0, sizeof(int) * (n + 1));
    dis[1] = 0;
    priority_queue<node> que;
    while (!que.empty())
        que.pop();
    que.emplace(node(1, 0, -1));
    while (!que.empty())
    {
        node cur = que.top();
        que.pop();
        int u = cur.to;
        int fa = cur.fa;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].first;
            int w = g[u][i].second;
            if (!vis[v])
            {
                int c = fa != w;
                if (dis[v] > dis[u] + c)
                {
                    dis[v] = dis[u] + c;
                    que.emplace(node(v, dis[v], w));
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n; i++)
            g[i].clear();
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            g[x].emplace_back(pa(y, z));
            g[y].emplace_back(pa(x, z));
        }
        dijk();
        cout << (dis[n] == inf ? -1 : dis[n]) << "\n";
    }
    return 0;
}
