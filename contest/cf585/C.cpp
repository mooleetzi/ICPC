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
char s[maxn], t[maxn];
set<int> pos, a, b;
vector<P> r;
int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    fastIO;
    cin >> n;
    cin >> s >> t;
    int aa = 0, bb = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            ++aa;
        else
            ++bb;
        if (t[i] == 'a')
            ++aa;
        else
            ++bb;
        if (s[i] != t[i])
        {
            if (s[i] == 'a')
                a.emplace(i);
            else
                b.emplace(i);
        }
    }
    if ((aa & 1) || (bb & 1))
    {
        puts("-1");
        return 0;
    }
    while (a.size() > 1)
    {
        int t1 = *a.begin();
        a.erase(t1);
        int t2 = *a.begin();
        a.erase(t2);
        r.emplace_back(t1, t2);
        swap(s[t1], t[t2]);
    }
    while (b.size() > 1)
    {
        int t1 = *b.begin();
        b.erase(t1);
        int t2 = *b.begin();
        b.erase(t2);
        r.emplace_back(t1, t2);
        swap(s[t1], t[t2]);
    }
    if (a.size() != b.size())
    {
        puts("-1");
        return 0;
    }
    if (a.size())
    {
        int t1 = *a.begin(), t2 = *b.begin();
        r.emplace_back(t1, t1);
        r.emplace_back(t2, t1);
    }
    cout << r.size() << "\n";
    for (auto x : r)
        cout << x.first + 1 << " " << x.second + 1 << "\n";
    return 0;
}