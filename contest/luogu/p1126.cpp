#include<bits/stdc++.h>
using namespace std;
const int maxn = 60;
const int inf = 0x3f3f3f3f;
int vis[maxn][maxn][6];
int ans[maxn][maxn];
int a[maxn][maxn];
int dx[4][3] = {{-1, -2, -3}, {0, 0, 0}, {1, 2, 3}, {0, 0, 0}};
int dy[4][3] = {{0, 0, 0}, {-1, -2, -3}, {0, 0, 0}, {1, 2, 3}};
struct node
{
    int x, y,step;
    char to;
    node(){}
    node(int a,int b,char c,int d){
        x = a, y = b, to = c,step=d;
    }
    int get(){
        if (to=='N')
            return 0;
        else if (to=='S')
            return 2;
        else if (to=='W')
            return 1;
        return 3;
    }
};
queue<node> que;
int sx, sy, ex, ey;
char sc;
int n, m;
int bfs(){
    que.push(node(sx, sy, sc,0));
    vis[sx][sy][node(sx, sy, sc,0).get()] = 1;
    while(!que.empty()){
        node now = que.front();
        que.pop();
        if (now.x==ex&&now.y==ey){
            printf("%d", now.step);
            return 1;
        }
        for (int i = 0; i < 3;i++){
            int tx = now.x + dx[now.get()][i];
            int ty = now.y + dy[now.get()][i];
            if (tx<=0||tx>=n||ty<=0||ty>=m||a[tx][ty])
                break;
            if (vis[tx][ty][now.get()])
                continue;
            vis[tx][ty][now.get()] = 1;
            que.push(node(tx, ty, now.to,now.step+1));
        }
        if (now.to=='N'||now.to=='S'){
            if (!vis[now.x][now.y][1]){
                vis[now.x][now.y][1] = 1;
                que.push(node(now.x, now.y, 'W', now.step + 1));
            }
            if (!vis[now.x][now.y][3]){
                vis[now.x][now.y][3] = 1;
                que.push(node(now.x, now.y, 'E', now.step + 1));
            }
        }
        else
        {
            if (!vis[now.x][now.y][0])
            {
                vis[now.x][now.y][0] = 1;
                que.push(node(now.x, now.y, 'N', now.step + 1));
            }
            if (!vis[now.x][now.y][2])
            {
                vis[now.x][now.y][2] = 1;
                que.push(node(now.x, now.y, 'S', now.step + 1));
            }
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
            if (a[i][j])
                a[i - 1][j] = a[i][j - 1] = a[i - 1][j - 1] = 1;
        }
    cin >> sx >> sy >> ex >> ey >> sc;
    int f = bfs();
    if (!f)
        printf("-1");
    return 0;
}

