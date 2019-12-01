#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
set<int> G[N], s;
int vis[N];
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    s.erase(x);
    while (q.size() > 0)
    {
        int y = q.front();
        q.pop();
        if (vis[y])
            continue;
        vis[y] = 1;

        for (auto it = s.begin(); it != s.end();)
        {
            int v = *it;
            ++it;
            if (G[y].find(v) == G[y].end())
            {
                q.push(v); //cout<<"-";
                s.erase(v);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        G[x].insert(y);
        G[y].insert(x);
    }
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
            ans++;
        }
    }
    cout << ans - 1 << "\n";
    return 0;
}