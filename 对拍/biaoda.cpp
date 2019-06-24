#include <algorithm>
#include <cstdio>
#include <memory.h>
#define maxn 101
using namespace std;
int n, k;
int Map[maxn][maxn], dp[maxn][maxn];
const int dir[4][2] = {0, -1, -1, 0, 0, 1, 1, 0};
int DFS(int a, int b)
{
    if (dp[a][b] != -1)
        return dp[a][b];
    int i, j, x, y, ans = Map[a][b];
    for (i = 0; i < 4; ++i)
    {
        for (j = 1; j <= k; ++j)
        {
            x = a + j * dir[i][0];
            y = b + j * dir[i][1];
            if (x < 0 || y < 0 || x >= n || y >= n || Map[x][y] <= Map[a][b])
                continue;
            ans = max(ans, DFS(x, y) + Map[a][b]);
        }
    }
    return dp[a][b] = ans;
}
int main()
{
    int i, j;
    while (~scanf("%d%d", &n, &k))
    {
        if (n == -1 && k == -1)
            break;
        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                scanf("%d", &Map[i][j]);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", DFS(0, 0));
    }
    return 0;
}