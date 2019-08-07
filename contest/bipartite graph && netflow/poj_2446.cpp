//根据是否可以被一个卡片铺满建立边
//题中建立的使双向边，所以求出的最大匹配为原图的二倍
//假设q为求出的最大匹配，此题应求最小点覆盖
//最小点覆盖=最大匹配
//即判断求出的最大匹配是否为非洞穴的格点数目，真为YES。
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
int n, m, k;
const int inf = 0x3f3f3f3f;
const int maxn = 35 * 35;
vector<int> g[maxn];
int uN;
int Mx[maxn], My[maxn];
int dx[maxn], dy[maxn];
int dis;
bool used[maxn];
bool SearchP()
{
    queue<int> Q;
    dis = inf;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 1; i <= uN; i++)
        if (Mx[i] == -1)
        {
            Q.push(i);
            dx[i] = 0;
        }
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        if (dx[u] > dis)
            break;
        int sz = g[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = g[u][i];
            if (dy[v] == -1)
            {
                dy[v] = dx[u] + 1;
                if (My[v] == -1)
                    dis = dy[v];
                else
                {
                    dx[My[v]] = dy[v] + 1;
                    Q.push(My[v]);
                }
            }
        }
    }
    return dis != inf;
}
bool DFS(int u)
{
    int sz = g[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = g[u][i];
        if (!used[v] && dy[v] == dx[u] + 1)
        {
            used[v] = true;
            if (My[v] != -1 && dy[v] == dis)
                continue;
            if (My[v] == -1 || DFS(My[v]))
            {
                My[v] = u;
                Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}
int MaxMatch()
{
    uN = n * m;
    int res = 0;
    memset(Mx, -1, sizeof(Mx));
    memset(My, -1, sizeof(My));
    while (SearchP())
    {
        memset(used, false, sizeof(used));
        for (int i = 1; i <= uN; i++)
            if (Mx[i] == -1 && DFS(i))
                res++;
    }
    return res;
}
int a[maxn][maxn];
int get_order(int x, int y)
{
    return (x - 1) * m + y;
}
void add(int x1, int y1, int x2, int y2)
{
    g[get_order(x1, y1)].push_back(get_order(x2, y2));
    g[get_order(x2, y2)].push_back(get_order(x1, y1));
}
void init()
{
    const int dx[] = {0, -1, 0, 1};
    const int dy[] = {1, 0, -1, 0};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (!a[i][j])
                for (int k = 0; k < 4; k++)
                {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (tx > 0 && tx <= n && ty > 0 && ty <= m && !a[tx][ty])
                        add(i, j, tx, ty);
                }
        }
}
void print()
{
    for (int i = 1; i <= n * m; i++)
    {
        printf("%d: ", i);
        int sz = g[i].size();
        for (int j = 0; j < sz; j++)
            printf("%d, ", g[i][j]);
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        for (int i = 1; i <= n * m; i++)
            g[i].clear();
        memset(a, 0, sizeof a);
        for (int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d%d", &y, &x);
            a[x][y] = 1; //有障碍
        }
        init();
        int res = MaxMatch();
        // printf("res: %d\n", res);
        if (res == n * m - k)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
