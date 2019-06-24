#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
using pa = pair<int, int>;
const int maxn = 1e3 + 10;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char a[maxn][maxn];
int vis[maxn][maxn];
int color[maxn][maxn];
int sx, sy, n, m,tot,num;
int ans[maxn*maxn];
inline int getXor(int x, int y, int tx, int ty)
{
    return a[x][y] != a[tx][ty];
}
void dfs(int x,int y,int c){
    color[x][y] = c;
    vis[x][y] = 1;
    ++num;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx>-1&&tx<n&&ty>-1&&ty<n&&!vis[tx][ty]&&getXor(x,y,tx,ty))
            dfs(tx, ty, c);
    }
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        cin >> a[i];
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            if (!vis[i][j]){
                num = 0;
                dfs(i, j, ++tot);
                ans[tot] = num;
            }
    for (int i = 0; i < m;i++){
        cin >> sx >> sy;
        cout << ans[color[sx-1][sy-1]] << "\n";
    }
    return 0;
}