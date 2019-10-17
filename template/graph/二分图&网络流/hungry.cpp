//hdu 2063 板题
#include <bits/stdc++.h>
using namespace std;
const int maxn = 502;
int a[maxn][maxn], b[maxn], girl[maxn];
int n, m, k;
int search(int g)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[g][i] && !b[i])
        {
            b[i] = 1;
            if (girl[i] == -1 || search(girl[i]))
            {
                girl[i] = g;
                return 1;
            }
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    while (read(k))
    {
        memset(girl, -1, sizeof girl);
        memset(a, 0, sizeof a);
        read(m);
        read(n);
        for (int i = 0; i < k; i++)
        {
            int x, y;
            read(x), read(y);
            a[x][y] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)
        {
            memset(b, 0, sizeof b);
            ans += search(i);
        }
        cout << ans << '\n';
    }
    return 0;
}
