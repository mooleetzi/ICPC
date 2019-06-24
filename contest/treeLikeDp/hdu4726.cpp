#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
typedef pair<int, int> pa;
vector<pa> g[maxn];
int n,t;
int dp[maxn][550];
int a[maxn];
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i < n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        g[y].push_back(pa(x, z));
    }
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    dfs(n, -1);
    return 0;
}
