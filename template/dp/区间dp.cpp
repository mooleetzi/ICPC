for (int i = 1; i <= n; i++)
    dp[i][i] = 初始值; //或memset(dp,0,sizeof(dp)) 初始化DP数组

for (int len = 2; len <= n; len++) //区间长度
    for (int i = 1; i <= n; i++)   //枚举起点
    {
        int j = i + len - 1; //区间终点
        if (j > n)
            break;                  //防止越界
        for (int k = i; k < j; k++) //枚举分割点，构造状态转移方程
        {
            dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + w[i][j]);
        }
    }