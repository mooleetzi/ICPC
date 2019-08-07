#include <bits/stdc++.h>
using namespace std;
const int maxn = 502;
int a[maxn][maxn], b[maxn], girl[maxn];
int n, m, k;
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
