
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10005;
int sum[maxn], n;
ll z[maxn], o[maxn], t[maxn];
ll dp[maxn], r[maxn][3];
struct Edge
{
    int v, w;
};
vector<Edge> tree[maxn];
void dfs(int cur, int father)
{
    sum[cur] = 1;
    int sz = tree[cur].size();
    for (int i = 0; i < sz; i++)
    {
        int son = tree[cur][i].v;
        ll len = tree[cur][i].w;
        if (father == son)
            continue;
        dfs(son, cur);
        sum[cur] += sum[son];
        dp[cur] += dp[son] + (n - sum[son]) * sum[son] * len;
        if (len % 3 == 0)
        {
            r[cur][0] += r[son][0] + (n - sum[son]) * sum[son] * len;
            r[cur][1] += r[son][1];
            r[cur][2] += r[son][2];
        }
        else if (len % 3 == 1)
        {
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d", &n))
    {
        r[0] = r[1] = r[2] = 0;
        for (int i = 0; i <= n; i++)
            tree[i].clear(), r[i][0] = r[i][1] = r[i][2] = 0;
        memset(sum, 0, sizeof(int) * (n + 1));
        memset(dp, 0, sizeof(ll) * (n + 1));
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            Edge t1, t2;
            t1.v = v;
            t1.w = w;
            t2.v = u;
            t2.w = w;
            tree[u].push_back(t1);
            tree[v].push_back(t2);
        }
        dfs(0, -1);
        ll res = dp[0] * 2;
    }
    return 0;
}