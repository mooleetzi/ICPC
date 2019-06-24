#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> g[maxn];
int ind[maxn];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        memset(ind, 0, sizeof ind);
        cin >> n >> m;
        int a[n + 1][m + 1];
        char s[n + 1][m + 1];
        int vis[n + 1][m + 1];
        memset(vis, 0, sizeof vis);
        for (int i = 0; i <= n * m; i++)
            g[i].clear();
        for (int i = 0; i < n; i++)
            cin >> s[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                int tx = i;
                int ty = j;
                if (s[i][j]=='u')
                    tx -= a[i][j];
                else if (s[i][j]=='d')
                    tx += a[i][j];
                else if (s[i][j]=='l')
                    ty -= a[i][j];
                else
                    ty += a[i][j];
                if (tx>=0&&tx<n&&ty>=0&&ty<m){
                    g[i * m + j].push_back(tx * m + ty);
                    ++ind[tx * m + ty];
                }
            }
        int x, y, minx = 1e9 + 7,tot=0;
        for (int i = 0; i < n;i++)
            for (int j = 0; j < m;j++){
                if (ind[i*m+j]<minx){
                    minx = ind[i * m + j];
                    x = i, y = j;
                }
                if (!ind[i * m + j])
                    ++tot;
            }
        if (n == 1 && m == 1)
        {
            cout << "Yes\n";
            continue;
        }
        if (tot>1)
            cout << "No\n";
        else{
            int cur = 1;
            vis[x][y] = 1;
            while(g[x*m+y].size()){
                int t = g[x * m + y][0];
                x = t / m;
                y = t % m;
                if (vis[x][y])
                    break;
                vis[x][y] = 1;
                ++cur;
            }
            if (cur==n*m)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}