#include <bits/stdc++.h>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pa = pair<int, int>;
using ld = long double;
int n, m, k;
const int maxn = 1e6 + 10;
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
int a[maxn];
int main(int argc, char const *argv[])
{
    read(n);
    int x, y;
    read(x);
    read(y);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    for (int i = 1; i <= n; i++)
    {
        int f = 1;
        for (int j = i - x; j > 0 && j < i; j++)
            if (a[j] <= a[i])
            {
                f = 0;
                break;
            }
        if (f)
        {
            for (int j = i + 1; j <= n && j <= i + y; j++)
                if (a[j] <= a[i])
                {
                    f = 0;
                    break;
                }
        }
        if (f)
        {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}
