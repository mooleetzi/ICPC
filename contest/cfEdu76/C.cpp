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
multiset<int> s;
unordered_map<int, int> pre, mp;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        pre.clear();
        n = read<int>();
        for (int i = 0; i < n; i++)
            a[i] = read<int>();
        int res = 1e9;
        for (int i = 0; i < n; i++)
        {
            if (pre.count(a[i]))
                res = min(i - pre[a[i]] + 1, res);
            pre[a[i]] = i;
        }
        writeln(res == 1e9 ? -1 : res);
    }
    return 0;
}
/*
        if (n < 2)
        {
            puts("-1");
            continue;
        }
        int pre = 0;
        int res = 1e9;
        int f = 0;
        for (int i = 1; i < n && !f; i++)
        {
            if (a[i] == a[i - 1])
            {
                puts("2");
                f = 1;
                break;
            }
        }
        if (f)
            continue;
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j < n)
            {
                if (s.size() > 1 && s.count(*s.rbegin()) == 1)
                {
                    res = min(res, j - i);
                    break;
                }
                if (mp.count(a[j]))
                    s.erase(s.find(mp[a[j]]));
                mp[a[j]]++;
                s.emplace(mp[a[j]]);
                ++j;
            }
            auto p = s.equal_range(mp[a[i]]);
            if (s.size() > 1 && s.count(*(s.rbegin())) == 1)
                res = min(res, j - i);
            s.erase(p.first);
            if (mp[a[i]] == 1)
                mp.erase(a[i]);
            else
                mp[a[i]]--;
            if (mp.count(a[i]))
                s.emplace(mp[a[i]]);
        }
        writeln(res == 1e9 ? -1 : res);
*/