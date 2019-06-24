#include<bits/stdc++.h>
using namespace std;
const int maxn = 110;
int vis[maxn][maxn];
int a[maxn][maxn];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
void bfs()
{
    queue<pair<int, int>> que;
    using pa = pair<int, int>;
    que.push(pa(0, 0));
    vis[0][0] = 1;
    if (a[0][0])
        return;
    while (!que.empty())
    {
        pa now = que.front();
        que.pop();
        for (int i = 0; i < 4;i++){
            int tx = now.first + dx[i];
            int ty = now.second + dy[i];
            if (tx>-1&&ty>-1&&tx<n&&ty<m&&!vis[tx][ty]&&!a[tx][ty]){
                vis[tx][ty] = 1;
                que.push(pa(tx, ty));
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++)
            cin >> a[i][j];
    bfs();
    if (vis[n-1][m-1])
        cout << "YES";
    else
    {
        cout << "NO";
    }

    return 0;
}