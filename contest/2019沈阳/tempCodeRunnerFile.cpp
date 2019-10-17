#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10005;
const int mod = 1e9 + 7;
struct node
{
    int v, dis, next;
} edges[N << 1];

int head[N], cnt, curNum;
int pre[N], dep[N];
int id[N];
int dis[N];
int rmq[N * 3][20];

int F[N * 3], B[N * 3];

int n, m, Q, root;

void add_edge(int u, int v, int dis)
{
    edges[cnt].v = v;
    edges[cnt].dis = dis;
    edges[cnt].next = head[u];
    head[u] = cnt++;
    edges[cnt].v = u;
    edges[cnt].dis = dis;
    edges[cnt].next = head[v];
    head[v] = cnt++;
}

void dfs(int u, int p, int depth, int d)
{
    curNum++;
    F[curNum] = u;
    B[curNum] = depth;
    dep[u] = depth;
    dis[u] = d;
    id[u] = curNum;
    pre[u] = p;
    for (int i = head[u]; ~i; i = edges[i].next)
    {
        int v = edges[i].v;
        if (v == p)
            continue;
        dfs(v, u, depth + 1, d + edges[i].dis);
        curNum++;
        B[curNum] = depth;
        F[curNum] = u;
    }
}

void initRmq()
{
    for (int i = 1; i <= curNum; i++)
        rmq[i][0] = i;
    for (int j = 1; (1 << j) <= curNum; j++)
        for (int i = 1; i + (1 << j) - 1 <= curNum; i++)
        {
            int x = rmq[i][j - 1];
            int y = rmq[i + (1 << (j - 1))][j - 1];
            rmq[i][j] = B[x] < B[y] ? x : y;
        }
}

int getLCA(int a, int b)
{
    int k, x, y;
    a = id[a];
    b = id[b];
    if (a > b)
        swap(a, b);
    k = log(1.0 + b - a) / log(2.0);
    x = rmq[a][k];
    y = rmq[b - (1 << k) + 1][k];
    return B[x] < B[y] ? F[x] : F[y];
}
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
inline void init()
{
    int u, v, dis;
    curNum = 0;
    memset(head, -1, sizeof(int) * (n + 1));
    cnt = 0;
    for (int i = 1; i < n; i++)
    {
        u = read<int>(), v = read<int>(), dis = read<int>();
        add_edge(u, v, dis);
    }
    root = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d", &n))
    {
        init();
        dfs(root, 0, 0, 0);
        initRmq();
        ll r[3];
        r[0] = r[1] = r[2] = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
            {
                ll d = dis[i] + dis[j] - 2 * dis[getLCA(i, j)];
                if (d >= mod)
                    d -= mod;
                r[d % 3] += d;
                if (r[d % 3] >= mod)
                    r[d % 3] -= mod;
            }
        write(2 * r[0]);
        putchar(' ');
        write(2 * r[1]);
        putchar(' ');
        write(2 * r[2]);
        puts("");
    }
    return 0;
}