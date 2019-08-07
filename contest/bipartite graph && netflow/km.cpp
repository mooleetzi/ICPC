#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int qwq = 0x7fffffff;
int w[1000][1000];                                          //w数组记录边权值
int line[1000], usex[1000], usey[1000], cx[1000], cy[1000]; //line数组记录右边端点所连的左端点， usex，usey数组记录是否曾访问过，也是判断是否在增广路上，cx，cy数组就是记录点的顶标
int n, ans, m;                                              //n左m右
bool find(int x)
{
    usex[x] = 1;
    for (int i = 1; i <= m; i++)
    {
        if ((usey[i] == 0) && (cx[x] + cy[i] == w[x][i]))
        { //如果这个点未访问过并且它是子图里面的边
            usey[i] = 1;
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
            int d = qwq;
            memset(usex, 0, sizeof(usex));
            memset(usey, 0, sizeof(usey));
            if (find(i))
                break; //直到成功匹配才换下一个点匹配
            for (int j = 1; j <= n; j++)
                if (usex[j])
                    for (int k = 1; k <= m; k++)
                        if (!usey[k])
                            d = min(d, cx[j] + cy[k] - w[j][k]); //计算d值
            if (d == qwq)
                return -1;
            for (int j = 1; j <= n; j++)
                if (usex[j])
                    cx[j] -= d;
            for (int j = 1; j <= m; j++)
                if (usey[j])
                    cy[j] += d; //添加新边
        }
    }
    ans = 0;
    for (int i = 1; i <= m; i++)
        ans += w[line[i]][i];
    return ans;
}
int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(cy, 0, sizeof(cy));
        memset(w, 0, sizeof(w));
        memset(cx, 0, sizeof(cx));
        for (int i = 1; i <= n; i++)
        {
            int d = 0;
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &w[i][j]);
                d = max(d, w[i][j]); //此处顺便初始化左边点的顶标
            }
            cx[i] = d;
        }
        memset(line, 0, sizeof(line));
        printf("%d\n", km());
    }
    return 0;
}