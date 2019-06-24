#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
unordered_map<string, int> in;
unordered_map<int, string> out;
vector<int> g[maxn];
int dp[maxn];
int n, num;
void dfs(int u,int fa){
    dp[u] = 1;
    for (int i = 0; i < g[u].size();i++){
        int v = g[u][i];
        if (v==fa)
            continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string s = "polycarp";
    for (int i = 0; i < n; i++)
    {
        string x, p, y;
        cin >> x >> p >> y;
        for (int i = 0; i < x.size(); i++)
            x[i] = tolower(x[i]);
        for (int i = 0; i < y.size(); i++)
            y[i] = tolower(y[i]);
        if (!in[x])
        {
            ++num;
            in[x] = num;
            out[num] = x;
        }
        if (!in[y])
        {
            ++num;
            in[y] = num;
            out[num] = y;
        }
        g[in[y]].push_back(in[x]);
    }
    dfs(in[s], -1);
    cout << dp[in[s]] << "\n";
    return 0;
}
