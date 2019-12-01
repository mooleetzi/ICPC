#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
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
#define pblank putchar(' ')
#define ll LL
#define fastIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, k;
const int maxn = 1e6 + 10;
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
ll t[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    ll k = read<ll>();
    for (int i = 1; i <= n; i++)
        t[i] = i;
    ll cur = (1LL + n) * n / 2;
    if (k < cur)
    {
        puts("-1");
        return 0;
    }
    else
    {
        int l = 1, r = n;
        while (l < r)
        {
            int temp = r - l;
            if (cur + temp <= k)
            {
                cur += temp;
                swap(t[l], t[r]);
                ++l, --r;
            }
            else
            {
                int tmp = k - cur + l;
                swap(t[tmp], t[l]);
                cur += tmp - l;
                break;
            }
        }
    }
    writeln(cur);
    for (int i = 1; i <= n; i++)
        write(i), pblank;
    puts("");
    for (int i = 1; i <= n; i++)
        write(t[i]), pblank;

    return 0;
}