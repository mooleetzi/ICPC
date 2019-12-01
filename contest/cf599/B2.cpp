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
int a[26], b[26];
string p, q;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    fastIO;
    int t;
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        cin >> n;
        cin >> p >> q;
        for (int i = 0; i < n; i++)
            ++a[p[i] - 'a'], ++b[q[i] - 'a'];
        int f = 1;
        for (int i = 0; i < 26 && f; i++)
            if ((a[i] + b[i]) & 1)
                f = 0;
        if (f)
        {
            puts("Yes");
            vector<P> res(0);
            for (int i = 0; i < n; i++)
                if (p[i] != q[i])
                {
                    int pos = 0;
                    for (int j = i + 1; j < n && !pos; j++)
                        if (p[j] == p[i])
                            pos = j;
                    if (pos)
                    {
                        res.emplace_back(pos, i);
                        swap(p[pos], q[i]);
                    }
                    else
                    {
                        int pos = 0;
                        for (int j = i + 1; j < n && !pos; j++)
                            if (q[j] == p[i])
                                pos = j;
                        res.emplace_back(n - 1, pos);
                        res.emplace_back(n - 1, i);
                        swap(p[n - 1], q[pos]);
                        swap(p[n - 1], q[i]);
                    }
                }
            int sz = res.size();
            writeln(sz);
            for (int i = 0; i < sz; i++)
                write_line(res[i].first + 1, res[i].second + 1);
        }
        else
            puts("No");
    }
    return 0;
}