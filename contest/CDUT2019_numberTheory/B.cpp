//思路就是质因子分解建二分图，且是双向边，然后跑最大匹配
//最后答案最大独立集应该是|E|-maxMatch
//由于是建的双向边，求出的最大匹配时两倍
//固最终答案应该是|E|-maxMatch/2
//此题卡匈牙利算法，只好抄了kuangbin聚聚的hk板子
//没用unordered_map:1500ms
//用了：700ms
//还有一种是根据质因子的奇偶性来建边，这样建的图跑出来就没有重复的匹配，不过还没理解
//看大佬博客是根据总的质因子数奇偶性建边，相同奇偶性的放一边
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxE = 5e5 + 10;
const int maxn = 4e4 + 10;
const int INF = 0x3f3f3f3f;
vector<int> G[maxn];
int uN;
int Mx[maxn], My[maxn];
int dx[maxn], dy[maxn];
int dis;
bool used[maxn];
bool SearchP()
{
    queue<int> Q;
    dis = INF;
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
        int sz = G[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = G[u][i];
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
    return dis != INF;
}
bool DFS(int u)
{
    int sz = G[u].size();
    for (int i = 0; i < sz; i++)
    {
        int v = G[u][i];
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
        for (int i = 1; i <= uN; i++)
            if (Mx[i] == -1 && DFS(i))
                res++;
    }
    return res;
}

template <class T>
inline void read(T &ret)
{
    int f = 1;
    ret = 0;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        ret = (ret << 1) + (ret << 3) + ch - '0';
        ch = getchar();
    }
    ret *= f;
}
template <class T>
inline void write(T n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n >= 10)
    {
        write(n / 10);
    }
    putchar(n % 10 + '0');
}
int a[maxn];
int xx, tot = 1;
unordered_map<int, int> pos;
int prime[maxE];
int notp[maxE];
int pcnt;
inline void init()
{
    for (int i = 2; i < maxE; i++)
    {
        if (!notp[i])
        {
            prime[pcnt++] = i;
            for (int j = 0; j < pcnt && i * prime[j] < maxE; j++)
            {
                notp[i * prime[j]] = 1;
                if (i % prime[j] == 0)
                    break;
            }
        }
    }
}
inline void add(int x, int id)
{
    int fac[maxn / 10];
    int tot = 0;
    for (int i = 0; prime[i] * prime[i] <= x; i++)
    {
        if (x % prime[i] == 0)
        {
            fac[tot++] = prime[i];
            while (x % prime[i] == 0)
                x /= prime[i];
        }
    }
    if (x > 1)
        fac[tot++] = x;
    x = a[id];
    for (int i = 0; i < tot; i++)
    {
        int cur = x / fac[i];
        if (pos[cur])
        {
            G[id].emplace_back(pos[cur]);
            G[pos[cur]].emplace_back(id);
        }
    }
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    // scanf("%d", &t);
    read(t);
    while (t--)
    {
        read(n);
        // scanf("%d", &n);
        pos.clear();
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
            // scanf("%d", &a[i]);
            pos[a[i]] = i;
            G[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            add(a[i], i);
        }
        uN = n;
        printf("Case %d: %d\n", tot++, n - MaxMatch() / 2);
    }
    return 0;
}
