#include<bits/stdc++.h>
using namespace std;
const int maxn = 60;
int vis[maxn][maxn];
char a[maxn][maxn];
int n,m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void dfs(int x,int y){
    for (int i = 0; i < 4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx>-1&&ty>-1&&tx<n&&ty<m&&!vis[tx][ty]&&a[tx][ty]=='1'){
            vis[tx][ty] = 1;
            dfs(tx, ty);
        }
    }
}
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n;i++)
            cin >> a[i];
        int ans = 0;
        for (int i = 0; i < n;i++)
            for (int j = 0; j < m;j++)
                vis[i][j] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == '1' && !vis[i][j])
                {
                    ++ans;
                    vis[i][j] = 1;
                    dfs(i, j);
                }
        cout << ans << "\n";
    }

    return 0;
}
