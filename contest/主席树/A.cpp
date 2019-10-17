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
const int maxn = 100010;
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
int a[maxn];
int root[maxn], cnt;
struct Node
{
    int l, r, sum;
} hjt[maxn * 40];
vector<int> v;
inline int getid(int x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
void insert(int l, int r, int pre, int &now, int x)
{
    hjt[++cnt] = hjt[pre];
    now = cnt;
    hjt[now].sum++;
    if (l == r)
        return;
    int m = l + r >> 1;
    if (x <= m)
        insert(l, m, hjt[pre].l, hjt[now].l, x);
    else
        insert(m + 1, r, hjt[pre].r, hjt[now].r, x);
}
int query(int l, int r, int L, int R, int k)
{
    if (l == r)
        return l;
    int m = l + r >> 1;
    int tmp = hjt[hjt[R].l].sum - hjt[hjt[L].l].sum;
    if (k <= tmp)
        return query(l, m, hjt[L].l, hjt[R].l, k);
    else
        return query(m + 1, r, hjt[L].r, hjt[R].r, k - tmp);
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), m = read<int>();
    for (int i = 1; i <= n; i++)
        v.push_back(a[i] = read<int>());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int vlen = v.size();
    for (int i = 1; i <= n; i++)
        insert(1, vlen, root[i - 1], root[i], getid(a[i]));
    while (m--)
    {
        int l = read<int>(), r = read<int>(), k = read<int>();
        writeln(v[query(1, vlen, root[l - 1], root[r], k) - 1]);
    }
    return 0;
}