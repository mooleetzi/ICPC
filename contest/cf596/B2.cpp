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
int n, m, k, d;
const int maxn = 1e6 + 10;
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
unordered_map<int, int> mp;
unordered_set<int> s;
int a[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        mp.clear();
        s.clear();
        n = read<int>(), k = read<int>(), d = read<int>();
        for (int i = 1; i <= n; i++)
            a[i] = read<int>();
        int head;
        int res = 1e9;
        for (int i = 1, j = 1; i <= n; i++)
        {
            head = a[i];
            while (j - i + 1 <= d && j <= n)
                s.emplace(a[j]), ++mp[a[j]], j++;
            if (j - i + 1 > d)
                res = min(res, (int)s.size());
            int t = mp[head];
            if (t == 1)
                s.erase(head), mp.erase(head);
            else
                --mp[head];
        }
        writeln(res);
    }
    return 0;
}