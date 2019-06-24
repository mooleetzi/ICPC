/*
    染色，计数，dfs/bfs
*/
#include<bits/stdc++.h>
using namespace std;
int f=1;
const int maxn = 2e5 + 10;
int vis[maxn], c[maxn];
vector<int> g[maxn];
using pa=pair<int,int>;
vector<pa> e;
inline int read()
{
    register int  ans = 0;
    char ch = getchar();
    while(!isdigit(ch)){
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans;
}
void dfs(int now,int color){
    if (!f)
        return;
    c[now] = color;
    for (int i = 0; i < g[now].size();i++){
        int to = g[now][i];
        if (c[to]==-1)
            dfs(to, color ^ 1);
        else if (c[to]==c[now]){
            f = 0;
            return;
        }
    }
}
int n, m;
int main(int argc, char const *argv[])
{
    n = read(), m = read();
    for (int i = 0; i < m;i++){
        int x, y;
        x = read(), y = read();
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        e.emplace_back(pa(x, y));
    }
    memset(c, -1, sizeof c);
    dfs(1, 0);
    if (f){
        cout << "YES\n";
        string ans = "";
        for (auto &x:e){
            int s = x.first;
            int t = x.second;
            if (c[s]&&!c[t])
                ans += "0";
            else
            {
                ans += "1";
            }
        }
        cout << ans << "\n";
    }
    else
        cout << "NO\n";
    return 0;
}
