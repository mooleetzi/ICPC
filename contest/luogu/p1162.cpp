#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 40;
int a[maxn][maxn];
int n;
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int vis[maxn][maxn];
inline int isok(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= n && !vis[x][y] && !a[x][y])
        return 1;
    return 0;
}
inline int read()
{
    register int f = 1, ans = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ans = (ans << 1) + (ans << 3) + ch - 48;
        ch = getchar();
    }
    return ans * f;
}
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = dx[i] + x;
        int ty = dy[i] + y;
        if (isok(tx,ty))
            dfs(tx, ty);
    }
}
void print(){
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!vis[i][j]&&!a[i][j]&&(i==1||j==1||i==n||j==n))
                dfs(i, j);
    // printf("\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (vis[i][j])
                printf("%d ", 0);
            else{
                
                printf("%d ", a[i][j]==0?2:1);
            }
        printf("\n");
    }
    return 0;
}