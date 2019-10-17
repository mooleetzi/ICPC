/*
    sg函数打表找规律
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
// int sg[maxn], vis[maxn];
// void init()
// {
//     sg[1] = 1;
//     for (int i = 2; i < 100; i++)
//     {
//         memset(vis, 0, sizeof vis);
//         for (int j = 1; j < i; j++)
//             vis[sg[i - j] ^ sg[j]] = 1, vis[sg[j]] = 1;
//         vis[0] = 1;
//         int k = 0;
//         while (vis[k])
//             ++k;
//         sg[i] = k;
//     }
//     for (int i = 1; i < 100; i++)
//     {
//         cout << sg[i] << " ";
//         if ((i + 1) % 10 == 0)
//             cout << endl;
//     }
// }
int sg(int x)
{
    if (x % 4 == 0)
        return x - 1;
    if (x % 4 == 3)
        return x + 1;
    return x;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    // init();
    int t = read<int>();
    for (int i = 0; i < t; i++)
    {
        n = read<int>();
        int res = 0;
        while (n--)
            res ^= sg(read<int>());
        if (res)
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}