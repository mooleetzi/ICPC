//二分图最大匹配板题
//建图方式：将每一排拆成两个坐位建图
//hk通过 100ms比hungry快了三倍
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
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
inline T read(T &ret)
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
    return ret;
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
inline short posl(int x)
{
    return (x - 1) << 1 | 1;
}
inline short posr(int x)
{
    return x << 1;
}
inline void add(int u, int x, int y)
{
    g[u].emplace_back(posl(x));
    g[u].emplace_back(posr(x));
    g[u].emplace_back(posl(y));
    g[u].emplace_back(posr(y));
}
int main(int argc, char const *argv[])
{
    read(n);
    for (int i = 1; i <= 2 * n; i++)
    {
        int x, y;
        read(x), read(y);
        add(i, x, y);
    }
    uN = 2 * n;
    int ans = MaxMatch();

    write(ans);
    return 0;
}
