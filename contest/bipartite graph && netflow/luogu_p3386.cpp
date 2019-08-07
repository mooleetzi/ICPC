//二分图最大匹配板题
//数据量较小，匈牙利算法即可
//注意内存限制，改int为short
//一定要学会HK算法！！！
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 1e3 + 10;
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
short visy[maxn], link[maxn];
short g[maxn][maxn];
int find(int u)
{
    for (int i = 1; i <= m; i++)
    {
        if (g[u][i] && !visy[i])
        {
            visy[i] = 1;
            if (!link[i] || find(link[i]))
            {
                link[i] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    read(n), read(m), read(k);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        read(x), read(y);
        if (x > n || y > m)
            continue;
        g[x][y] = 1;
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
