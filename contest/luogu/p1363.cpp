#include<bits/stdc++.h>
// #define DEBUG
using namespace std;
using pa = pair<int, int>;
const int maxn = 1510;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};
int n, m,sx,sy;
int vis[maxn][maxn][3];
char a[maxn][maxn];
int dis[maxn][maxn];
int f;
void print()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++)
            cout << vis[i][j] << " ";
        cout << "\n";
    }
}
void dfs(int x,int y,int lx,int ly){
    if (f)
        return;
    if (vis[x][y][0]&&(vis[x][y][1]!=lx||vis[x][y][2]!=ly)){
        f = 1;
        return;
    }
    vis[x][y][0] = 1;
    vis[x][y][1] = lx;
    vis[x][y][2] = ly;
    for (int i = 0; i < 4; i++)
    {
        int tx = (x + dx[i] + n) % n;
        int ty = (y + dy[i] + m) % m;
        int ttx = lx + dx[i];
        int tty = ly + dy[i];
        if (a[tx][ty]=='.'||a[tx][ty]=='S')
            if (vis[tx][ty][1] != ttx || vis[tx][ty][2] != tty ||!vis[tx][ty][0])
            dfs(tx, ty, ttx, tty);
    }
}
int main(int argc, char const *argv[])
{
    while (cin>>n>>m)
    {
        for (int i = 0; i < n;i++){
            cin >> a[i];
            for (int j = 0; j < m;j++){
                if (a[i][j]=='S'){
                    sx = i;
                    sy = j;
                }
                vis[i][j][0] = 0;
                vis[i][j][1] = vis[i][j][2] = -1;
            }
        }
        f = 0;
        dfs(sx, sy, sx, sy);
        if (f)
            cout << "Yes\n";
        else
        {
            cout << "No\n";
        }

#ifdef DEBUG
        print();
#endif
    }
    return 0;
}
