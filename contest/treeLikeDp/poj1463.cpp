/*
    求图里最小点覆盖
    最小点覆盖=最大匹配数
    但hungry算法n^2会t
    树形dp o(n)稳妥
*/
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn = 1510;
vector<int> g[maxn];
int n, dp[maxn][2];
void dfs(int u,int fa){
    dp[u][1] = 1;
    dp[u][0] = 0;
    for (int i = 0; i < g[u].size();i++){
        int v = g[u][i];
        if (v==fa)
            continue;
        dfs(v,u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][1], dp[v][0]);
    }
}
int main(int argc, char const *argv[])
{
    while(~scanf("%d",&n)){
        for (int i = 0; i < n;i++)
            g[i].clear();
        int rt;
        for (int i = 0; i < n;i++){
            int x, c;
            scanf("%d:(%d)", &x, &c);
            for (int j = 0; j < c;j++){
                int y;
                scanf("%d", &y);
                g[x].push_back(y);
                g[y].push_back(x);
            }
        }
        dfs(0,-1);
        printf("%d\n", min(dp[0][0],dp[0][1]));
    }
    return 0;
}
