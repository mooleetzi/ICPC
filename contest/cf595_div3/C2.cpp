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
ull n, m, k;
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
ull p[50];
void init()
{
    p[0] = 1;
    for (int i = 1; i < 50; i++)
        p[i] = p[i - 1] * 3;
}
vector<int> t3;
ull solve()
{
    t3.clear();
    while (n)
    {
        t3.emplace_back(n % 3);
        n /= 3;
    }
    int sz = t3.size();
    int f = -1;
    for (int i = 0; i < sz; i++)
        if (t3[i] == 2 || t3[i] == 3)
        {
            f = i;
            if (i != sz - 1)
            {
                t3[i] = 0;
                t3[i + 1]++;
            }
            else
            {
                t3[i] = 0;
                t3.emplace_back(1);
            }
        }
    sz = t3.size();
    ull res = 0;
    if (f != -1)
        for (int i = 0; i < f; i++)
            t3[i] = 0;
    for (int i = 0; i < sz; i++)
        if (t3[i])
            res += p[i];
    return res;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    init();
    int t = read<int>();
    while (t--)
    {
        n = read<ull>();
        writeln(solve());
    }
    return 0;
}