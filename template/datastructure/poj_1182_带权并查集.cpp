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
const int maxn = 5e4 + 10;
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
int fa[maxn], r[maxn];
int find(int p)
{
    while (fa[p] != fa[fa[p]])
    {
        r[p] = (r[p] + r[fa[p]]) % 3;
        fa[p] = fa[fa[p]];
    }
    return fa[p];
}
void merge(int x, int y, int d)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        fa[fy] = fx;
        r[fy] = (r[x] - r[y] + 3 + (d - 1)) % 3;
    }
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), k = read<int>();
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int ans = 0;
    while (k--)
    {
        int op = read<int>(), a = read<int>(), b = read<int>();
        if (a > n || b > n)
        {
            ++ans;
            continue;
        }
        if (find(a) == find(b))
        {
            if (op == 1 && r[a] != r[b])
                ++ans;
            else if (op == 2 && (r[a] + 1) % 3 != r[b])
                ++ans;
        }
        else
            merge(a, b, op);
    }
    writeln(ans);
    return 0;
}