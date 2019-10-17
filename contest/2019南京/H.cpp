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
int n, m, k;
const int maxn = 310;
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
int v[1001], w[1001], nxt[1001];
int d[maxn], cnt[maxn], first[maxn];
bool flag, vis[maxn];
int tot = 0;
void add(int x, int y, int z)
{
    tot++;
    nxt[tot] = first[x];
    first[x] = tot;
    v[tot] = y;
    w[tot] = z;
}
bool spfa()
{
    int x, y, i, j;
    queue<int> q;
    memset(d, 127, sizeof(d));
    memset(vis, false, sizeof(vis));
    while (!q.empty())
        q.pop();
    d[0] = 0;
    cnt[0] = 1;
    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        vis[x] = false;
        for (i = first[x]; ~i; i = nxt[i])
        {
            y = v[i];
            if (d[y] > d[x] + w[i])
            {
                d[y] = d[x] + w[i];
                cnt[y] = cnt[x] + 1;
                if (cnt[y] > n)
                    return false;
                if (!vis[y])
                {
                    q.push(y);
                    vis[y] = true;
                }
            }
        }
    }
    return true;
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
        int ans[6];
        }
    return 0;
}
