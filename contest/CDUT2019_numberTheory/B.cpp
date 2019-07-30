#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
// #define DEBUG
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxE = 5e5 + 10;
const int maxn = 4e4 + 10;
const int INF = 0x3f3f3f3f;
vector<int> G[maxE];
int uN;
short Mx[maxn], My[maxn];
short dx[maxn], dy[maxn];
int dis;
bool used[maxn];
bool SearchP()
{
    queue<int> Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 0; i < uN; i++)
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
        for (int i = 0; i < uN; i++)
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
short p[maxE];
int a[maxn];
short h[maxn];
unordered_set<int> ss;
unordered_set<int> s1, s2;
void init()
{
    for (int i = 3; i < maxE; i += 2)
        p[i] = 1;
    p[2] = 1;
    for (int i = 2; i < maxE; i++)
        if (p[i])
            for (int j = 2 * i; j < maxE; j += i)
                p[j] = 0;
}
int main(int argc, char const *argv[])
{
    init();
    int t;
    read(t);
    int tot = 1;
    while (t--)
    {
        ss.clear();
        s1.clear();
        s2.clear();
        read(n);
        int maxx = 0;
        for (int i = 0; i < n; i++)
            read(a[i]), ss.insert(a[i]), maxx = max(maxx, a[i]);
        for (int i = 1; i <= maxx; i++)
            G[i].clear();
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            int m = sqrt(x);
            for (int j = 1; j <= m; j++)
            {
                if (x % j == 0)
                {

                    int k = x / j;
                    if (p[k] && ss.count(j))
                    {
                        G[j].emplace_back(x);
                        ++uN;
                    }
                    if (p[j] && ss.count(k))
                    {
                        ++uN;
                        G[k].emplace_back(x);
                    }
                }
            }
        }
        printf("Case %d: %u\n", tot++, n - MaxMatch());
    }
    return 0;
}
