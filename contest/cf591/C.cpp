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
int n, m;
ll k;
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
ll c[maxn];
int x, y, a, b;
inline int judge(int mid){
    ll cur = 0;
    int l = 1;
    for (int i = 1; i <= mid;i++)
        if (i%a==0&&i%b==0)
            cur += c[l++] * (x + y)/100;
    for (int i = 1; i <= mid;i++)
        if (i%b==0&&i%a!=0)
            cur += c[l++] * y / 100;
    for (int i = 1; i <= mid;i++)
        if (i%a==0&&i%b!=0)
            cur += c[l++] * x / 100;
    return cur >= k;
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
        for (int i = 1; i <= n; i++)
            c[i] = read<ll>();
        x = read<int>(), a = read<int>();
        y = read<int>(), b = read<int>();
        k = read<ll>();
        sort(c + 1, c + 1 + n);
        reverse(c + 1, c + 1 + n);
        if (x>y)
            swap(a, b), swap(x, y);
        int l = 1, r = n, res = -1;
        while (l<=r)
        {
            int mid = l + r >> 1;
            if (judge(mid)){
                res = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        writeln(res);
    }
    return 0;
}