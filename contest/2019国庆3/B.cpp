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
int n, m, k;
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
int c[maxn];
inline int lowbit(int x) { return x & (-x); }
void add(int x, int y)
{
    while (x < maxn)
    {
        c[x] += y;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int res = 0;
    while (x)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
int solve(int n)
{
    memset(c, 0, sizeof(int) * (n + 5));
    char ch[20];
    int len = 0;
    while (n)
    {
        ch[len++] = n % 10 + '0';
        n /= 10;
    }
    reverse(ch, ch + len);
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        int cur = ch[i] - '0' + 1;
        res += sum(cur);
        add(cur, 1);
    }
    return res;
}
void init()
{
    int res = 0;
    for (int i = 1; i <= 100; i++)
        res += solve(i);
    writeln(res);
}
int main(int argc, char const *argv[])
{
    // #ifndef ONLINE_JUDGE
    //     freopen("in.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif
    init();
    return 0;
}