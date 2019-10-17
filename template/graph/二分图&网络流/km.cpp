#include <cstdio>
#include <cstring>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e3 + 10;
int k, m, n, x, y;
int visx[maxn], visy[maxn], wx[maxn], wy[maxn], minz, lx[maxn], ly[maxn], slack[maxn], a[maxn][maxn];
int find(int x)
{
    visx[x] = 1;
    for (int v = 1; v <= y; v++)
    {
        if (!visy[v])
        {
            int t = wx[x] + wy[v] - a[x][v];
            if (!t)
            {
                visy[v] = 1;
                if (ly[v] == -1 || find(ly[v]))
                {
                    ly[v] = x;
                    lx[x] = x;
                    return 1;
                }
            }
            else if (slack[v] > t)
            {
                slack[v] = t;
            }
        }
    }
    return 0;
}
int KM()
{
    memset(ly, -1, sizeof ly);
    memset(wy, 0, sizeof wy);
    for (int i = 1; i <= x; i++)
    {
        wx[i] = -inf;
        for (int j = 1; j <= y; j++)
            if (a[i][j] > wx[i])
                wx[i] = a[i][j];
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
            slack[j] = inf;
        while (1)
        {
            memset(visx, 0, sizeof visx);
            memset(visy, 0, sizeof visy);
            if (find(i))
                break;
            int d = inf;
            for (int j = 1; j <= y; j++)
            {
                if (!visy[j] && d > slack[j])
                    d = slack[j];
            }
            for (int j = 1; j <= x; j++)
                if (visx[j])
                    wx[j] -= d;
            for (int j = 1; j <= y; j++)
                if (visy[j])
                    wy[j] += d;
                else
                    slack[j] -= d;
        }
    }
    int ans = 0;
    for (int i = 1; i <= y; i++)
        if (ly[i] != -1)
            ans += a[ly[i]][i];
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    memset(a, 0, sizeof a);
    cin >> x >> y >> k;
    for (int i = 1; i <= k; i++)
    {
        int q, w, e;
        cin >> q >> w >> e;
        a[q][w] = e;
    }
    int ans = KM();
    cout << ans << "\n";
    return 0;
}
