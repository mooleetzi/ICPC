//二分图最大匹配板题
//hungry 31ms
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 1e2 + 10;
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
int ly[maxn];
int visy[maxn];
vector<int> g[maxn];
int find(int u)
{
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!visy[v])
        {
            visy[v] = 1;
            if (!ly[v] || find(ly[v]))
            {
                ly[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    read(m), read(n);
    int x, y;
    while (read(x) != -1 && read(y) != -1)
    {
        g[x].emplace_back(y);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        memset(visy, 0, sizeof visy);
        ans += find(i);
    }
    write(ans);
    putchar('\n');
    for (int i = m + 1; i <= n; i++)
        if (ly[i])
        {
            write(ly[i]);
            putchar(' ');
            write(i);
            putchar('\n');
        }
    return 0;
}
