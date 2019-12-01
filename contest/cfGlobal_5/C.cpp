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
struct point
{
    int x, y, z, idx;
    point() {}
    point(int xx, int yy, int zz, int i) : x(xx), y(yy), z(zz), idx(i) {}
};
bool cmp1(const point &t1, const point &t2)
{
    return t1.z < t2.z;
}
bool cmp2(const point &t1, const point &t2)
{
    return t1.x ^ t2.x ? t1.x < t2.x : t1.y < t2.y;
}
vector<point> vz, vx, vy;
int vis[maxn];
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    n = read<int>();
    for (int i = 0; i < n; i++)
        vz.emplace_back(read<int>(), read<int>(), read<int>(), i + 1);
    sort(vz.begin(), vz.end(), cmp1);
    vector<point> tmp;
    tmp.clear();
    for (int i = 0; i < n;)
    {
        int j = i;
        vx.clear();
        while (j < n && vz[j].z == vz[i].z)
            vx.emplace_back(vz[j++]);
        sort(vx.begin(), vx.end(), cmp2);
        int sz = vx.size();
        vy.clear();
        for (int k = 0; k < sz;)
        {
            int p = k;
            while (p < sz && vx[k].x == vx[p].x)
                ++p;
            if ((p - k) & 1)
                vy.emplace_back(vx[k]), k++;
            for (int it = k; it < p; it += 2)
                write(vx[it].idx), pblank, writeln(vx[it + 1].idx);
            k = p;
        }
        sz = vy.size();
        if (sz & 1)
            tmp.emplace_back(vy.back()), vy.pop_back(), sz--;
        for (int i = 0; i < sz; i += 2)
            write(vy[i].idx), pblank, writeln(vy[i + 1].idx);
        i = j;
    }
    int sz = tmp.size();
    for (int i = 0; i < sz; i += 2)
        write(tmp[i].idx), pblank, writeln(tmp[i + 1].idx);
    return 0;
}