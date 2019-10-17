/*
    整数拆分，将奇数看作1，偶数看作0
    要使n个数满足k份和皆为奇数，即需要每一份都至少有一个奇数
    在此基础上，每一份可加上偶数个奇数
    因此只要奇数个数sz>=k且(sz-k)为偶数，即yes，任意输出答案
*/
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define LONG_LONG_MAX 9223372036854775807LL
#define ll LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
vector<int> r;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q = read<int>();
    while (q--)
    {
        r.clear();
        n = read<int>(), k = read<int>();
        for (int i = 0; i < n; i++)
        {
            int x = read<int>();
            if (x & 1)
            {
                r.emplace_back(i + 1);
            }
        }
        int sz = r.size();
        if (sz >= k && !((sz - k) & 1))
        {
            puts("YES");
            for (int i = 0; i < k - 1; i++)
                write(r[i]), putchar(' ');
            write(n);
            puts("");
        }
        else
            puts("NO");
    }
    return 0;
}
