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
vector<int> g[100];
inline int _hash(vector<int> &t)
{
    int p = 1;
    for (int i = 0; i < 4; i++)
        p = (p * 2017 + t[i]) % 10007;
    return p;
}
inline int isok()
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int p = _hash(g[i]);
        if (s.count(p))
            return 0;
        s.emplace(p);
    }
    return 1;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        n = read<int>();
        for (int i = 0; i < n; i++)
            g[i].clear();
        for (int i = 0; i < n; i++)
        {
            char s[10];
            scanf("%s", s);
            for (int j = 0; j < 4; j++)
                g[i].emplace_back(s[j] - '0');
        }
        int res = 0;
        while (!isok())
        {
            unordered_map<int, int> mp;
            mp.clear();
            for (int i = 0; i < n; i++)
                mp[_hash(g[i])]++;
            for (int i = 0; i < n; i++)
            {
                int p = _hash(g[i]);
                if (mp[p] == 1)
                    continue;
                for (int j = 0; j < 4; j++)
                {
                    int f = 1;
                    for (int k = 0; k < 10 && f; k++)
                    {
                        int tmp = g[i][j];
                        g[i][j] = k;
                        if (!mp[_hash(g[i])])
                        {
                            mp[_hash(g[i])] = 1;
                            f = 0;
                            ++res;
                        }
                    }
                    if (!f)
                        break;
                }
                mp[p]--;
            }
        }
        writeln(res);
        for (int i = 0; i < n; i++)
        {
            for (int j : g[i])
                write(j);
            puts("");
        }
    }
    return 0;
}