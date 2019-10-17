/*
    hdu_6181
    次短路径
*/
using ll = long long;
using pa = pair<ll, int>;
const ll inf = 1e18;
const int maxn = 1e5 + 10;
struct edge
{
    int to, nxt;
    ll dis;
} e[maxn << 1];
int head[maxn << 1];
int tot = 0, m, n;
ll d1[maxn], d2[maxn];
void add(int x, int y, int z)
{
    e[tot].to = y;
    e[tot].dis = z;
    e[tot].nxt = head[x];
    head[x] = tot++;
}
void dijkstra()
{
    for (int i = 0; i <= n; i++)
        d1[i] = d2[i] = inf;
    priority_queue<pa, vector<pa>, greater<pa>> que; //优先队列里的greater从小到大
    while (!que.empty())
        que.pop();
    d1[1] = 0;
    que.push(pa(0, 1));
    while (!que.empty())
    {
        pa now = que.top();
        que.pop();
        int u = now.second;
        ll c = now.first;
        if (d2[u] < c)
            continue;
        for (int i = head[u]; ~i; i = e[i].nxt)
        {
            int v = e[i].to;
            int dis = e[i].dis;
            ll nowd2 = c + dis;
            if (d1[v] > nowd2)
            {
                swap(d1[v], nowd2);
                que.push(pa(d1[v], v));
            }
            if (d2[v] > nowd2 && d1[v] < nowd2)
            {
                d2[v] = nowd2;
                que.push(pa(d2[v], v));
            }
        }
    }
}
inline int read()
{
    int ans = 0;
    char ch = getchar();
    while (isdigit(ch))
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        tot = 0;
        memset(head, -1, sizeof(head));
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
        }
        dijkstra();
        printf("%lld\n", d2[n]);
    }
    return 0;
}
