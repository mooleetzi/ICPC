//对于p，q数组相乘得到权值数组w（建图完成）
//直接跑二分图最佳匹配km算法
//emm还没有正经写过km，这次是贴板子
#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int inf = 0x3f3f3f3f;
const int maxn = 25;
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
int p[maxn][maxn], q[maxn][maxn];
int w[maxn][maxn];
int lx[maxn], ly[maxn], vx[maxn], vy[maxn], line[maxn];
bool find(int x)
{
    vx[x] = 1;
    for (int i = 1; i <= n; i++)
    {
        if ((vy[i] == 0) && (lx[x] + ly[i] == w[x][i]))
        { //如果这个点未访问过并且它是子图里面的边
            vy[i] = 1;
            if ((line[i] == 0) || find(line[i]))
            { //如果这个点未匹配或者匹配点能更改
                line[i] = x;
                return true;
            }
        }
    }
    return false;
}
int km()
{
    for (int i = 1; i <= n; i++)
    { //分别对左边点依次匹配
        while (true)
        {
            int d = inf;
            memset(vx, 0, sizeof(vx));
            memset(vy, 0, sizeof(vy));
            if (find(i))
                break; //直到成功匹配才换下一个点匹配
            for (int j = 1; j <= n; j++)
                if (vx[j])
                    for (int k = 1; k <= n; k++)
                        if (!vy[k])
                            d = min(d, lx[j] + ly[k] - w[j][k]); //计算d值
            if (d == inf)
                return -1;
            for (int j = 1; j <= n; j++)
                if (vx[j])
                    lx[j] -= d;
            for (int j = 1; j <= n; j++)
                if (vy[j])
                    ly[j] += d; //添加新边
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += w[line[i]][i];
    return ans;
}
int main(int argc, char const *argv[])
{
    read(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            read(p[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            read(q[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            w[i][j] = p[i][j] * q[j][i];
    memset(ly, 0, sizeof(ly));
    memset(lx, 0, sizeof(lx));
    for (int i = 1; i <= n; i++)
    {
        int d = 0;
        for (int j = 1; j <= n; j++)
        {
            d = max(d, w[i][j]); //此处顺便初始化左边点的顶标
        }
        lx[i] = d;
    }
    memset(line, 0, sizeof(line));
    printf("%d\n", km());
    return 0;
}
