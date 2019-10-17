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
const int BASE = 64, maxn = 5e5 + 10;
int val[maxn][BASE], pos[maxn][BASE];
inline void insert(int i, int x)
{
    int k = i, tmp;
    for (int j = BASE - 1; j >= 0; --j)
        val[i][j] = val[i - 1][j], pos[i][j] = pos[i - 1][j];
    for (int j = BASE - 1; j >= 0; --j)
        if (x >> j)
        {
            if (!val[i][j])
            {
                val[i][j] = x;
                pos[i][j] = k;
                break;
            }
            else
            {
                if (k > pos[i][j])
                {
                    tmp = k, k = pos[i][j], pos[i][j] = tmp;
                    tmp = x, x = val[i][j], val[i][j] = tmp;
                }
                x ^= val[i][j];
            }
        }
}
inline void init()
{
    for (int i = 1; i <= n; ++i)
        for (int j = BASE - 1; j >= 0; --j)
            val[i][j] = pos[i][j] = 0;
}
inline int query(int l, int r)
{
    int ans = 0;
    for (int j = BASE - 1; j >= 0; --j)
        if ((ans ^ val[r][j]) > ans && pos[r][j] >= l)
            ans ^= val[r][j];
    return ans;
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
        for (int i = 1; i <= n; ++i)
            insert(i, read<int>());
        int ans = 0;
        while (m--)
        {
            int op = read<int>();
            if (op)
            {
                ++n;
                int x = read<int>() ^ ans;
                insert(n, x);
            }
            else
            {
                int l = read<int>(), r = read<int>();
                l = (l ^ ans) % n + 1, r = (r ^ ans) % n + 1;
                if (l > r)
                    swap(l, r);
                ans = query(l, r);
                write(ans);
                puts("");
            }
        }
    }
    return 0;
}