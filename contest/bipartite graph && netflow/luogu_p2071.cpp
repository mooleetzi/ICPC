//二分图最大匹配板题
//建图方式：将每一排拆成两个坐位建图
//hungry通过 300ms
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
short line[maxn];
bool visy[maxn];
vector<short> g[maxn];
bool find(int u)
{
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!visy[v])
        {
            visy[v] = 1;
            if (!line[v] || find(line[v]))
            {
                line[v] = u;
                return 1;
            }
        }
    }
    return 0;
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
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        memset(visy, 0, sizeof visy);
        ans += find(i);
    }
    write(ans);
    return 0;
}
