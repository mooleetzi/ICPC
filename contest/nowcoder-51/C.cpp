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
#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#endif
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
ll n, m, k;

ll a, b;
const int maxn = 1e5 + 10;
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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
inline bool istwo(ll x)
{
    int t = log2(x);
    return (1LL << t) == x;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<ll>();
    if (n < 3)
        puts("-1");
    else if (istwo(n))
    {
        ll div = n / 4;
        write(div * 3);
        putchar(' ');
        writeln(div * 5);
    }
    else
    {
        int f = 1;
        for (ll i = 1; i * i <= n && f; i++)
        {
            if (n % i == 0)
            {
                ll j = n / i;
                if (i & 1 && i > 1)
                {
                    write(i * i / 2 * j);
                    putchar(' ');
                    writeln(((i * i) / 2 + 1) * j);
                    f = 0;
                }
                if (j & 1 && j > 1)
                {
                    write(j * j / 2 * i);
                    putchar(' ');
                    writeln(((j * j) / 2 + 1) * i);
                    f = 0;
                }
            }
        }
        if (f)
            puts("-1");
    }

    return 0;
}