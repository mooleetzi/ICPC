/*
    带权并查集
    向量思维
*/
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
int r[maxn], fa[maxn];
int find(int x)
{
    while (fa[x] != fa[fa[x]])
    {
        r[x] = (r[x] ^ r[fa[x]]);
        fa[x] = fa[fa[x]];
    }
    return fa[x];
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        fa[fy] = fx;
        r[fy] = (r[x] - r[y] + 1) % 2;
    }
}
void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i, r[i] = 0;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        n = read<int>(), m = read<int>();
        init();
        while (m--)
        {
            char c = getchar();
            int x = read<int>(), y = read<int>();
            if (n == 2 && c == 'A')
            {
                puts("In different gangs.\n");
                continue;
            }
            if (c == 'A')
            {
                int fx = find(x), fy = find(y);
                if (fx != fy)
                {
                    puts("Not sure yet.");
                }
                else
                {
                    if (r[x] != r[y])
                        puts("In different gangs.");
                    else
                    {
                        puts("In the same gang.");
                    }
                }
            }
            else
            {
                merge(x, y);
            }
        }
    }
    return 0;
}