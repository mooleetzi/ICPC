#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long ll;
typedef pair<int, int> eg;
struct edge
{
    int from, to, w;
    edge(int s, int t, int q)
    {
        from = s, to = t, w = q;
    }
    edge() {}
    int operator<(const edge &a) const
    {
        return w < a.w;
    }
};
edge e[maxn];
vector<eg> h[maxn];
ll n, m;
ll ans;
int sum[maxn];
double dp[maxn];
int rnk[maxn];
double ep;
int fa[maxn];
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    if (x!=y){
        if (rnk[x]<rnk[y])
            fa[x] = y;
        else{
            fa[y] = x;
            if (rnk[x]==rnk[y])
                ++rnk[x];
        }
    }
}
void dfs(int cur, int fa)//求树上任意两点距离之和
{
    sum[cur] = 1;
    for (int i = 0; i < h[cur].size(); i++)
    {
        int to = h[cur][i].first;
        int len = h[cur][i].second;
        if (fa == to)
            continue;
        dfs(to, cur);
        sum[cur] += sum[to];
        dp[cur] += dp[to] + ((double)sum[to] * (n - sum[to])) * (double)len;
    }
}
int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%I64d%I64d", &n, &m);
        ans = 0, ep = 0;
        for (int i = 1; i <= n;i++){
            fa[i] = i;
            dp[i] = sum[i] = rnk[i] = 0;
            h[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            e[i] = edge(x, y, z);
        }
        sort(e, e + m);
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            edge now = e[i];
            int x = find(now.from), y = find(now.to);
            if (x!=y)
            {
                ans += now.w;
                merge(x, y);
                ++cnt;
                h[now.from].emplace_back(eg(now.to, now.w));
                h[now.to].emplace_back(eg(now.from, now.w));
            }
        }
        dfs(1, -1);
        ep = 2 * dp[1] / ((n - 1) * n*1.0);
        printf("%I64d %.2f\n", ans, ep);
    }
    return 0;
}
