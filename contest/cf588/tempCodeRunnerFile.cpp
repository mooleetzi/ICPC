#include <algorithm>
#include <numeric>
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
int x[8], y[8];
int col[8], vis[8][8];
int ans;
void dfs(int now){
    if (now>n){
        int cur = 0;
        memset(vis ,0, sizeof vis);
        for (int i = 0; i < m;i++){
            int ta = col[x[i]], tb = col[y[i]];
            if (!vis[ta][tb])
                ++cur, vis[ta][tb] = vis[tb][ta] = 1;
        }
        ans = max(cur, ans);
        return;
    }
    for (int i = 1; i <= 6;i++)
        col[now] = i, dfs(now + 1);
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    n = read<int>(), m = read<int>();
    for (int i = 0; i < m;i++)
        x[i] = read<int>(), y[i] = read<int>();
    dfs(1);
    writeln(ans);
    return 0;
}