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
const int N = 100010;
const int LOG_N = 22;
vector<int> mp[N];
int ind[N], root, parent[LOG_N][N], depth[N];

void dfs(int v, int p, int d)
{
    depth[v] = d;
    parent[0][v] = p;
    int sz = mp[v].size();
    for (int i = 0; i < sz; i++)
    {
        if (mp[v][i] != p)
            dfs(mp[v][i], v, d + 1);
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

int main()
{
    // freopen("in.txt", "r", stdin);

    int T, n, a, b;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(ind, 0, sizeof ind);
        for (int i = 0; i < N; i++)
            mp[i].clear();
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%d%d", &a, &b);
            mp[a].push_back(b);
            mp[b].push_back(a);
            ind[b]++;
        }
        for (int i = 1; i <= n; i++)
            if (!ind[i])
            {
                root = i;
                break;
            }
        init(n);
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}