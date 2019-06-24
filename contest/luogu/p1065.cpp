#include<bits/stdc++.h>
using namespace std;
const int maxn = 10;
int a[maxn][maxn];
int vis[maxn][maxn];
int ans = 0;
int sx, sy, ex, ey,n,m,t;
int isok(int x,int y){
    if (x<1||y<1||x>n||y>m||vis[x][y])
        return 0;
    return 1;
}
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
using pa = pair<int, int>;
vector<pa> now;
void dfs(int x, int y)
{
    if (x==ex&&y==ey){
        ++ans;
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (isok(tx,ty)){
            dfs(tx, ty);
        }
    }
    vis[x][y] = 0;
}
int main(){
    cin>>n>>m>>t;
    cin >> sx >> sy >> ex >> ey;
    while(t--){
        int x, y;
        cin >> x >> y;
        vis[x][y] = 1;
    }
    dfs(sx, sy);
    cout << ans << "\n";
    return 0;
}