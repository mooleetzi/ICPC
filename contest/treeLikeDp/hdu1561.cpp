#include<bits/stdc++.h>
using namespace std;
const int maxn = 210;
vector<int> g[maxn];
int dp[maxn][maxn];
int n, m,ans;
void dfs(int u,int fa,int w){
    for (int i = 0; i < g[u].size();i++){
        int v = g[u][i];
        if (v==fa)
            continue;
        dfs(v, u, w - 1);//选了父节点，子节点最多选w-1个
        for (int j = w; j > 1;j--)//01背包第二层循环逆序
            for (int k = 1; k <=j;k++)
                dp[u][j] = max(dp[u][j], dp[u][k] + dp[v][j-k]);
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m&&(n&&m)){
        memset(dp, 0, sizeof dp);
        for (int i = 0; i <= n;i++)
            g[i].clear();
        for (int i = 1; i <= n;i++){
            int a, b;
            cin >> a >> b;
            g[a].push_back(i);
            dp[i][1] = b;
        }
        ++m;
        dfs(0, -1, m);//0号节点不算，故应当++m
        cout << dp[0][m] << "\n";
    }
    return 0;
}
