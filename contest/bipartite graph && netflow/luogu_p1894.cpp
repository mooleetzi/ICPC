//二分图最大匹配裸题目，匈牙利算法
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 220;
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
int visy[maxn], line[maxn], g[maxn][maxn];
int find(int u)
{
    for (int i = 1; i <= m; i++)
    {
        if (g[u][i] && !visy[i])
        {
            visy[i] = 1;
            if (!line[i] || find(line[i]))
            {
                line[i] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    read(n), read(m);
    for (int i = 1; i <= n; i++)
    {
        int t;
        read(t);
        for (int j = 1; j <= t; j++)
        {
            int now;
            read(now);
            g[i][now] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(visy, 0, sizeof visy);
        ans += find(i);
    }
    write(ans);
    return 0;
}
