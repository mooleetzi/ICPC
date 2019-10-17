/*
    倍增lca
    luoguP3379
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned int, unsigned int> puu;
typedef pair<int, double> pid;
typedef pair<ll, int> pli;

const int INF = 0x3f3f3f3f;
const int N = 500010;
const int LOG_N = 22;
struct node
{
    int to, nxt;
} e[N << 1];
int ind[N], root, tot, parent[LOG_N][N], depth[N], head[N];
void add(int x, int y)
{
    e[++tot].nxt = head[x];
    e[tot].to = y;
    head[x] = tot;
}
void dfs(int v, int p, int d)
{
    depth[v] = d;
    parent[0][v] = p;
    for (int i = head[v]; i; i = e[i].nxt)
    {
        int u = e[i].to;
        if (u != p)
            dfs(u, v, d + 1);
    }
}

void init(int n)
{
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < LOG_N; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[k][i] < 0)
                parent[k + 1][i] = -1;
            else
                parent[k + 1][i] = parent[k][parent[k][i]];
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] > depth[v])
        swap(u, v);
    for (int i = 0; i < LOG_N; i++)
    {
        if ((depth[v] - depth[u]) >> i & 1)
            v = parent[i][v];
    }
    if (u == v)
        return u;
    for (int i = LOG_N - 1; i >= 0; i--)
    {
        if (parent[i][u] != parent[i][v])
        {
            v = parent[i][v];
            u = parent[i][u];
        }
    }
    return parent[0][u];
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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
int main()
{
    // freopen("in.txt", "r", stdin);

    int T, n, a, b, m;
    n = read<int>(), m = read<int>(), root = read<int>();
    for (int i = 0; i < n - 1; i++)
    {
        a = read<int>(), b = read<int>();
        add(a, b);
        add(b, a);
    }
    init(n);
    for (int i = 0; i < m; i++)
    {
        a = read<int>();
        b = read<int>();
        writeln(lca(a, b));
    }
    return 0;
}