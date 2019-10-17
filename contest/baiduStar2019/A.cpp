#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 1e4 + 10;
template <class T>
inline T read()
{
    int f = 1;
    T ret = 0;
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
int a[maxn], b[maxn];

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        n = read<int>();
        memset(a, 0, sizeof(int) * (n + 1));
        memset(b, 0, sizeof(int) * (n + 1));
        for (int i = 0; i < n; i++)
            a[i] = read<int>();
        for (int i = 0; i < n; i++)
            b[i] = read<int>();
        int t = n - 1;
        while (1)
        {
            if (a[t] && b[t])
            {

                int g = __gcd(abs(a[t]), abs(b[t]));
                a[t] /= g, b[t] /= g;
                printf("%d/%d\n", a[t], b[t]);
                break;
            }
            else if (a[t])
            {
                printf("1/0\n");
                break;
            }
            else if (b[t])
            {
                printf("0/1\n");
                break;
            }
            t--;
        }
    }
    return 0;
}
