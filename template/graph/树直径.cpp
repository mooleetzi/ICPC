/*
    树形dp求直径
*/
void dp(int x)
{
    v[x] = 1;
    for (int i = head[x]; i; i = net[i])
    {
        int y = ver[i];
        if (v[y])
            continue;
        dp(y);
        ans = max(ans, d[x] + d[y] + edge[i]);
        d[x] = max(d[x], d[y] + edge[i]);
    }
}

/*
    DFS求树的直径
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100086;
struct picture
{
    int y, v, net;
    int pre;
} e[maxn];
int lin[maxn], len = 0;
int n, m, dis[maxn];
bool vis[maxn];
int start, end;

inline int read()
{
    int x = 0, y = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            y = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * y;
}

inline void insert(int xx, int yy, int vv)
{
    e[++len].y = yy;
    e[len].v = vv;
    e[len].net = lin[xx];
    e[len].pre = xx;
    lin[xx] = len;
}

void dfs(int st)
{
    vis[st] = 1;
    for (int i = lin[st]; i; i = e[i].net)
    {
        int to = e[i].y;
        if (!vis[to])
        {
            dis[to] = dis[st] + e[i].v;
            dfs(to);
        }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f3f3f, sizeof(dis));
    n = read(), m = read();
    for (int i = 1; i <= m; ++i)
    {
        int x, y, v;
        x = read(), y = read(), v = read();
        insert(x, y, v);
        insert(y, x, v);
    }
    dis[1] = 0;
    dfs(1);
    int maxx = -1000;
    for (int i = 1; i <= n; ++i)
        if (dis[i] > maxx && dis[i] != 1061109567)
        {
            maxx = dis[i];
            start = i;
        }
    cout << maxx << ' ' << start << '\n';
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f3f3f, sizeof(dis));
    dis[start] = 0;
    dfs(start);
    maxx = -1000;
    for (int i = 1; i <= n; ++i)
        if (dis[i] > maxx && dis[i] != 1061109567)
        {
            maxx = dis[i];
            end = i;
        }
    cout << start << ' ' << maxx << ' ' << end << '\n';
    return 0;
}

/*
    BFS求树的直径
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 100086;
const ll inf = 1061109567;
struct picture
{
    int y, net, v;
    int pre;
} e[maxn];
int n, m;
int lin[maxn], len = 0;
int dis[maxn];
int q[maxn], head = 0, tail = 0;
int start, end;
bool vis[maxn];

inline int read()
{
    int x = 0, y = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            y = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * y;
}

inline void insert(int xx, int yy, int vv)
{
    e[++len].pre = xx;
    e[len].y = yy;
    e[len].v = vv;
    e[len].net = lin[xx];
    lin[xx] = len;
}

inline void bfs(int st)
{
    head = tail = 0;
    vis[st] = 1;
    q[++tail] = st;
    while (head < tail)
    {
        //cout << head << '\n';
        for (int i = lin[q[++head]]; i; i = e[i].net)
        {
            int to = e[i].y;
            if (!vis[to])
            {
                dis[to] = dis[q[head]] + e[i].v;
                vis[to] = 1;
                q[++tail] = to;
            }
        }
    }
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; ++i)
    {
        int x, y, v;
        x = read(), y = read(), v = read();
        insert(x, y, v);
        insert(y, x, v);
    }
    memset(dis, 0x3f3f3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0;
    bfs(1);
    int maxx = -1000;
    for (int i = 1; i <= n; ++i)
        if (dis[i] > maxx && dis[i] != inf)
        {
            start = i;
            maxx = dis[i];
        }
    cout << maxx << ' ' << start << '\n';
    memset(dis, 0x3f3f3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[start] = 0;
    bfs(start);
    maxx = -1000;
    for (int i = 1; i <= n; ++i)
        if (dis[i] > maxx && dis[i] != inf)
        {
            end = i;
            maxx = dis[i];
        }
    cout << start << ' ' << maxx << ' ' << end << '\n';
    return 0;
}