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
const int maxn = 3e5 + 10;
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
vector<int> a;
int l[maxn], r[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    int t = read<int>();
    while (t--)
    {
        n = read<int>();
        a.clear();
        for (int i = 1; i <= n; i++)
            l[i] = 1e9, r[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = read<int>();
            a.emplace_back(x);
            if (l[x] == 1e9)
                l[x] = i;
            r[x] = i;
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int sz = a.size();
        int res = 1;
        int cur = 1;
        for (int i = 1; i < sz; i++){
            if (l[a[i]] > r[a[i-1]])
                ++cur;  
            else
                cur = 1;
            res = max(res, cur);
        }
        writeln(sz-res);
    }
    return 0;
}