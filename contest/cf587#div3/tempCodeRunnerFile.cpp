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
template <typename T>
void _write(const T &t)
{
    write(t);
}
template <typename T, typename... Args>
void _write(const T &t, Args... args)
{
    write(t), pblank;
    _write(args...);
}
template <typename T, typename... Args>
inline void write_line(const T &t, const Args &... data)
{
    _write(t, data...);
}
struct node
{
    int x1, y1, x2, y2;
    node() {}
    node(int a, int b, int c, int d)
    {
        x1 = a, y1 = b, x2 = c, y2 = d;
    }
    ll area()
    {
        return (x2 - x1) *1LL* (y2 - y1);
    }
};
ll cal(const node &t1, const node &t2)
{
    node tmp;
    tmp.y2 = min(t2.y2, t1.y2);
    tmp.y1 = max(t1.y1, t2.y1);
    tmp.x2 = min(t1.x2, t2.x2);
    tmp.x1 = max(t1.x1, t2.x1);
    return tmp.area();
}
inline int check(const node&t1,const node &t2){
    node tmp;
    tmp.x1 = max(t1.x1, t2.x1);
    tmp.x2 = min(t1.x2, t2.x2);
    tmp.y1 = max(t1.y1, t2.y1);
    tmp.y2 = min(t1.y2, t2.y2);
    if (tmp.x1>tmp.x2||tmp.y1>tmp.y2)
        return 0;
    return 1;
}
inline node intersection(const node &t1,const node &t2){
    node tmp;
    tmp.x1 = max(t1.x1, t2.x1);
    tmp.x2 = min(t1.x2, t2.x2);
    tmp.y1 = max(t1.y1, t2.y1);
    tmp.y2 = min(t1.y2, t2.y2);
    return tmp;
}
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt","w", stdout);
#endif
    vector<node> vec(3);
    for (int i = 0; i < 3; i++)
    {
        int x1 = read<int>(), y1 = read<int>(), x2 = read<int>(), y2 = read<int>();
        vec[i] = node(x1, y1, x2, y2);
    }
    ll p1 = intersection(vec[0], vec[1]).area() ,p2= intersection(vec[0], vec[2]).area();
    ll now = p1 + p2;
    now -= intersection(vec[0], intersection(vec[1], vec[2])).area();
    if (now >= vec[0].area())
        puts("NO");
    else
        puts("YES");
    return 0;
}