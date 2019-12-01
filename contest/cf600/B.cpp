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
}
int a[maxn];
map<int, int> mp;
set<int> s;
vector<int> res;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 0; i < n; i++)
        a[i] = read<int>();
    if (n & 1)
    {
        puts("-1");
        return 0;
    }
    int pre = -1, f = 1;
    for (int i = 0; i < n && f; i++)
    {
        if (a[i] > 0)
        {
            if (mp.count(a[i]) || s.count(a[i]))
                f = 0;
            else
                mp[a[i]] = 1, s.emplace(a[i]);
        }
        else
        {
            if (!mp.count(-a[i]))
                f = 0;
            else
                mp.erase(-a[i]);
        }
        if (mp.empty())
        {
            res.emplace_back(i - pre);
            pre = i;
            s.clear();
        }
    }
    if (f)
    {
        int tmp = accumulate(res.begin(), res.end(), 0);
        if (tmp == n)
        {
            writeln(res.size());
            for (int i = 0; i < res.size(); i++)
                write(res[i]), pblank;
            puts("");
        }
        else
        {
            puts("-1");
        }
    }
    else
        puts("-1");
    return 0;
}