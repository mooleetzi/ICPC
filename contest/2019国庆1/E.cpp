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
int n, m, k, x;
const int maxn = 1e5 + 10;
int a[maxn], vis[maxn];
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
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> m >> n >> x)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            vis[i] = 0;
        }
        sort(a + 1, a + n + 1);
        int p = 0, q = 0;
        for (int i = 1; i <= x; i++)
            for (int j = 1; j <= n; j++)
            {
                if (a[j] == 1 && p + q < m)
                    ++p;
                else if (i % a[j])
                {
                    if (!vis[j] && p + q < m)
                    {
                        vis[j] = 1;
                        ++q;
                    }
                }
                else
                {
                    if (vis[j])
                    {
                        vis[j] = 0;
                        ++p;
                        --q;
                    }
                }
            }
        cout << m - p - q << " " << q << "\n";
    }
    return 0;
}