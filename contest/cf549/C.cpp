#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int fa[maxn],c[maxn];
int del[maxn];
vector<int> g[maxn];
vector<int> ans;
void dfs(int x)
{
    int f = 1;
    for (int i = 0; i < g[x].size(); i++){
        if (c[g[x][i]]==0)
            f = 0;
        dfs(g[x][i]);
    }
    if (c[x]&&f){
        ans.emplace_back(x);
    }
}
int main(int argc, char const *argv[])
{
    cin >> n;
    int rt;
    for (int i = 0; i < n; i++)
    {
        cin >> fa[i + 1] >> c[i + 1];
        g[fa[i + 1]].emplace_back(i + 1);
        if (fa[i+1]==-1)
            rt = i + 1;
    }
    dfs(rt);
    sort(ans.begin(), ans.end());
    if (ans.empty())
        cout << "-1";
    else
    {
        for (auto x:ans)
            cout << x << " ";
    }

    return 0;
}
