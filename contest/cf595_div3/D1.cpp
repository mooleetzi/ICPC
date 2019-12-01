/*
    给n个区间，一个上界k
    问最少删除多少区间，使得区间内任一点的覆盖数不大于k
    贪心策略，从左往右找每个需要删区间的点，对于区间选择采取满足l<=i且r最大
    由于区间和n值较小，O(n^3)亦可过
*/
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
template <class T>
inline void writeln(const T &n)
{
    write(n);
    puts("");
}
struct node
{
    int l, r, idx;
    node() {}
    node(int l, int r, int idx)
    {
        this->l = l, this->r = r, this->idx = idx;
    }
    bool operator<(const node &t1) const
    {
        if (r == t1.r)
            return l < t1.l;
        return r < t1.l;
    }
};

vector<node> vec;
int p[202], del[202];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>(), k = read<int>();
    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {

        int x = read<int>(), y = read<int>();
        maxx = max(maxx, y);
        vec.emplace_back(x, y, i);
        for (int j = x; j <= y; j++)
            ++p[j];
    }
    for (int i = 1; i <= maxx; i++)
    {
        while (p[i] > k)
        {
            int rr = 0, delid = -1;
            for (int j = 0; j < n; j++)
                if (!del[j] && vec[j].l <= i && vec[j].r > rr)
                {
                    rr = vec[j].r;
                    delid = j;
                }
            for (int j = vec[delid].l; j <= vec[delid].r; j++)
                --p[j];
            del[delid] = 1;
        }
    }
    int res = accumulate(del, del + n, 0);
    writeln(res);
    for (int i = 0; i < n; i++)
        if (del[i])
            write(i + 1), putchar(' ');
    return 0;
}