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
const int maxn = 1e2 + 10;
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
char s[maxn], ans[maxn];
int vis[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof vis);
        cin >> n;
        int a, b, c;
        cin >> a >> b >> c;
        cin >> s + 1;
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (s[i] == 'P' && c)
                --c, ans[i] = 'S', ++res, vis[i] = 1;
            else if (s[i] == 'S' && a)
                --a, ans[i] = 'R', ++res, vis[i] = 1;
            else if (s[i] == 'R' && b)
                --b, ans[i] = 'P', ++res, vis[i] = 1;
        int p = n / 2;
        if (n & 1)
            ++p;
        if (res >= p)
        {
            cout << "YES\n";
            for (int i = 1; i <= n; i++)
                if (!vis[i])
                {
                    if (a)
                        ans[i] = 'R',--a;
                    else if (b)
                        ans[i] = 'P',--b;
                    else if (c)
                        ans[i] = 'S',--c;
                    vis[i] = 1;
                }
            ans[n + 1] = '\0';
            cout << ans + 1 << "\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}