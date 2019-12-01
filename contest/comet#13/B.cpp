#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
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
list<P> res;
int tot = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
unordered_map<char, int> mp;
void init()
{
    mp['W'] = 3;
    mp['A'] = 1;
    mp['S'] = 2;
    mp['D'] = 0;
}
char s[500][500];
char r[maxn];
void run(int hx, int hy, int p = 0)
{
    if (p)
    {
        res.emplace_front(hx, hy);
        ++tot;
    }
    else
    {
        int px = res.back().first, py = res.back().second;
        s[px][py] = '.';
        res.pop_back();
        res.emplace_front(hx, hy);
    }
}
void solve()
{
    int len = strlen(r);
    int x = res.front().first, y = res.front().second;
    for (int i = 0; i < len; i++)
    {
        int dic = mp[r[i]];
        int hx = x + dx[dic], hy = y + dy[dic];
        if (hx < 1 || hx > n || hy < 1 || hy > m)
        {
            cout << "GG";
            return;
        }
        if (s[hx][hy] == 'o')
        {
            run(hx, hy, 1);
            s[hx][hy] = '.';
        }
        else
            run(hx, hy);
        x = hx, y = hy;
    }
    auto head = res.front();
    for (auto it : res)
    {
        int x = it.first, y = it.second;
        if (x == head.first && y == head.second)
            s[x][y] = '@';
        else
            s[x][y] = 'X';
    }
    for (int i = 1; i <= n; i++)
        cout << s[i] + 1 << "\n";
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    init();
    fastIO;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] + 1;
        if (!tot)
            for (int j = 1; j <= m; j++)
                if (s[i][j] == '@')
                {
                    ++tot;
                    res.emplace_back(P(i, j));
                }
    }
    cin >> r;
    solve();
    return 0;
}