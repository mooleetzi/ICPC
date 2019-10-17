/*
    尼姆博弈
        n堆石子，每堆a[i]个，xor=a[1]^a[2]...^a[n]
        xor=0先手败
        否则先手胜
    此题使用异或前缀和求得N的P后继
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
const int maxn = 2e5 + 10;
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
int pre[maxn], a[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    while (n = read<int>())
    {
        for (int i = 1; i <= n; i++)
            a[i] = read<int>(), pre[i] = pre[i - 1] ^ a[i];
        if (pre[n])
        {
            puts("Yes");
            for (int i = 1; i <= n; i++)
            {
                int cur = a[i];
                int t1 = pre[n] ^ pre[i];
                int t2 = pre[i - 1];
                t1 ^= t2;
                if (cur >= t1)
                    printf("%d %d\n", cur, t1);
            }
        }
        else
            puts("No");
    }
    return 0;
}