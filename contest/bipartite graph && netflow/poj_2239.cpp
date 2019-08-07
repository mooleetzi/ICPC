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
const int maxn = 310;
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
    uN = n;
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
inline int get_order(int d1, int d2)
{
    return 12 * (d1 - 1) + d2;
}
int main(int argc, char const *argv[])
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i <= n; i++)
        {
            int t;
            scanf("%d", &t);
            while (t--)
            {
                int d1, d2;
                scanf("%d%d", &d1, &d2);
                g[i].push_back(get_order(d1, d2));
                // printf("order: %d\n", get_order(d1, d2));
            }
        }
        int ans = MaxMatch();
        printf("%d\n", ans);
    }
    return 0;
}
