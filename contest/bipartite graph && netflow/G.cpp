/*
    二分图最大匹配+删边判断是否任然保持最大匹配
    hk15ms
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
const int maxn = 1e2 + 10;
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
// const int maxn = 1e2 + 10;
const int inf = 0x3f3f3f3f;
vector<int> g[maxn];
int uN;
int Mx[maxn], My[maxn];
int dx[maxn], dy[maxn];
int dis;
bool used[maxn];
bool SearchP()
{
    queue<int> Q;
    dis = inf;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 1; i <= uN; i++) //注意是否从1开始标号
        if (Mx[i] == -1)
        {
            Q.push(i);
            dx[i] = 0;
        }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis)
            break;
        int sz = g[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = g[u][i];
            if (dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (My[v] == -1)
                    dis = dy[v];
                else
                {
                    dx[My[v]] = dy[v] + 1;
                    Q.push(My[v]);
                }
            }
        }
    }
    return dis != inf;
}
bool DFS(int u)
{
    int sz = g[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = g[u][i];
        if (!used[v] && dy[v] == dx[u] + 1)
        {
            used[v] = true;
            if (My[v] != -1 && dy[v] == dis)
                continue;
            if (My[v] == -1 || DFS(My[v]))
            {
                My[v] = u;
                Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}
int MaxMatch()
{
    int res = 0;
    memset(Mx, -1, sizeof(Mx));
    memset(My, -1, sizeof(My));
    while (SearchP())
    {
        memset(used, false, sizeof(used));
        for (int i = 1; i <= uN; i++) //注意是否从1开始标号
            if (Mx[i] == -1 && DFS(i))
                res++;
    }
    return res;
}
vector<pa> vec;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tot = 1;
    while (cin >> n >> m >> k)
    {
        vec.clear();
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            // cout << x << " " << y << " xxx\n";
            g[x].emplace_back(y);
            vec.emplace_back(x, y);
        }
        for (int i = 1; i <= n; i++)
        {
            sort(g[i].begin(), g[i].end());
        }
        uN = n;
        int mm = MaxMatch();
        int sz = vec.size();
        int res = 0;
        for (int i = 0; i < sz; i++)
        {
            pa cur = vec[i];
            int pf = cur.first, ps = cur.second;
            // cout << pf << " " << ps << "\n";
            auto it = lower_bound(g[pf].begin(), g[pf].end(), ps);
            // cout << *it << "\n";
            g[pf].erase(it);
            int nowm = MaxMatch();
            if (nowm < mm)
                ++res;
            g[cur.first].emplace_back(cur.second);
            sort(g[pf].begin(), g[pf].end());
        }
        cout << "Board " << tot++ << " have " << res << " important blanks for " << mm << " chessmen.\n";
    }
    return 0;
}
