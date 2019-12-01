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
template <typename T>
void _write(const T &t)
{
    write(t);
}
template <typename T, typename... Args>
void _write(const T &t, Args... args)
{
    write(t), pblank;
    _write(args...);
}
template <typename T, typename... Args>
inline void write_line(const T &t, const Args &... data)
{
    _write(t, data...);
    puts("");
}
char s[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        vector<P> res;
        res.clear();
        n = read<int>();
        k = read<int>();
        scanf("%s", s);
        for (int i = 0; i < k - 1; i++)
        {
            int curx = i * 2;
            if (s[curx] == '(')
            {
                if (s[curx + 1] == '(')
                {
                    int tox = 0;
                    for (int j = curx + 2; j < n && !tox; j++)
                        if (s[j] == ')')
                            tox = j;
                    res.emplace_back(curx + 1, tox);
                    reverse(s + curx, s + tox + 1);
                }
            }
            else
            {
                int tox = 0;
                for (int j = curx + 1; j < n && !tox; j++)
                    if (s[j] == '(')
                        tox = j;
                res.emplace_back(curx, tox);
                reverse(s + curx, s + tox + 1);
                i--;
            }
        }
        int tox = k - 1 << 1;
        int left = n - tox >> 1;
        for (int i = tox, j = 0; i < n; i++, j++)
        {
            if (j < left)
            {
                if (s[i] == ')')
                {
                    int tx = 0;
                    for (int q = i + 1; q < n && !tx; q++)
                        if (s[q] == '(')
                            tx = q;
                    res.emplace_back(i, tx);
                    reverse(s + i, s + tx + 1);
                }
            }
        }
        writeln(res.size());
        for (auto x : res)
            write_line(x.first + 1, x.second + 1);
    }
    return 0;
}