int num[20], tot;
ll dp[20][2];
inline ll dfs(int now, int pre, int limit)
{
    if (!now)
        return 1;
    if (!limit && dp[now][pre] != -1)
        return dp[now][pre];
    int up = limit ? num[now] : 9;
    ll ret = 0;
    for (int i = 0; i <= up; i++)
    {
        if (i == 4 || (pre && i == 2))
            continue;
        ret += dfs(now - 1, i == 6, limit && i == up);
    }
    if (!limit)
        dp[now][pre] = ret;
    return ret;
}
inline ll solve(ll x)
{
    tot = 0;
    memset(dp, -1, sizeof dp);
    while (x)
        num[++tot] = x % 10, x /= 10;
    return dfs(tot, 0, 1);
}