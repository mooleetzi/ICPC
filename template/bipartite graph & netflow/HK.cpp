const int maxn = 4e3 + 10;
const int inf = 0x3f3f3f3f;
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
    for (int i = 1; i <= uN; i++) //注意是否从1开始标号
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
    int res = 0;
    memset(Mx, -1, sizeof(Mx));
    memset(My, -1, sizeof(My));
    while (SearchP())
    {
        memset(used, false, sizeof(used));
        for (int i = 1; i <= uN; i++) //注意是否从1开始标号
            if (Mx[i] == -1 && DFS(i))
                res++;
    }
    return res;
}