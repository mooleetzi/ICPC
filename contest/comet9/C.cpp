#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
vector<int> g[maxn];
int deg[maxn], deep[maxn];

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    queue<int> q;
    n = read<int>(), k = read<int>();
    for (int i = 0; i < n - 1; i++)
    {
        int x = read<int>(), y = read<int>();
        g[x].emplace_back(y), g[y].emplace_back(x);
        ++deg[x], ++deg[y];
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] == 1)
        {
            q.emplace(i);
            deep[i] = 1;
        }
    int lst = n, ans;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        --lst;
        deg[u] = 0;
        if (lst == k)
        {
            ans = deep[u];
            break;
        }
        int sz = g[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = g[u][i];
            --deg[v];
            deep[v] = max(deep[v], deep[u] + 1);
            if (deg[v] == 1)
                q.emplace(v);
        }
    }
    write(ans);
    return 0;
}
