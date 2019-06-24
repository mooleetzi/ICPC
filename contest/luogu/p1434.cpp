#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int a[maxn][maxn],vis[maxn][maxn];
int f[maxn][maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans,m,n;
int dfs(int x, int y){
    if (f[x][y])
        return f[x][y];
    int ans = 0;
    for (int i = 0; i <4;i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx>0&&ty>0&&ty<=m&&tx<=n&&a[tx][ty]<a[x][y]){
            ans = max(ans, dfs(tx, ty) + 1);
        }
    }
    return f[x][y] = ans;
}
inline int read(){
    char ch = getchar();
    register int f = 1, ans = 0;
    while (!isdigit(ch))
    {
        if (ch=='-')
            f = -1;
        ch = getchar();
        /* code */
    }
    while (isdigit(ch))
    {
        ans = (ans << 3) + (ans << 1) + ch - 48;
        ch = getchar();
        /* code */
    }
    return ans * f;
}
void print(int f[][maxn]){
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++)
            cout << f[i][j] << " ";
        cout << "\n";
    }
}
int main(int argc, char const *argv[])
{
    // cin >> n >> m;
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m;j++)
            a[i][j] = read();
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            ans = max(ans, dfs(i, j)+1);
    cout << ans;
    return 0;
}
