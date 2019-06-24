#include<bits/stdc++.h>
using namespace std;
const int maxn = 500;
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {-2, 2, -1, 1, 2, -2, 1, -1};
int ans[maxn][maxn];
int vis[maxn][maxn];
int n, m;
int sx, sy;
struct node
{
    int x, y, step;
    node(int a,int b,int c):x(a),y(b),step(c){}
    node(){}
    /* data */
};
queue<node> que;
int main(int argc, char const *argv[])
{
    cin >> n >> m >> sx >> sy;
    memset(ans, -1, sizeof ans);
    ans[sx][sy] = 0;
    que.push(node(sx, sy, 0));
    vis[sx][sy] = 1;
    while (!que.empty())
    {
        node now = que.front();
        que.pop();
        int x = now.x, y = now.y, step = now.step;
        for (int i = 0; i < 8; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx>0&&ty>0&&tx<=n&&ty<=m&&!vis[tx][ty]){
                que.push(node(tx, ty, step + 1));
                ans[tx][ty] = step + 1;
                vis[tx][ty] = 1;
            }
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++)
            cout <<setw(5)<<left<<ans[i][j];
        cout << "\n";
    }
    return 0;
}

